#include "pch.h"
#include "Game.h"
#include <assert.h>

Game::Game() :
    cWidthSize(28)
    , cHeightSize(32)
    , isGame(false)
{
    setWindow(cWidthSize, cHeightSize);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(mConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(mConsole, &cursorInfo);

    mPrintBuffer = new CHAR_INFO[cWidthSize * cHeightSize];

    mBufferSize.X = cWidthSize;
    mBufferSize.Y = cHeightSize;


    mBufferCoord.X = 0;
    mBufferCoord.Y = 0;

    mWriteRegion.Left = 0;
    mWriteRegion.Top = 0;
    mWriteRegion.Right = cWidthSize + 1;
    mWriteRegion.Bottom = cHeightSize + 1;

    mPlayField = std::make_shared<PlayField>(cWidthSize, cHeightSize);

    mPlayField->addFigure(FigureFactory::createFigure(FigureType::CYAN));
    mPlayField->addFigure(FigureFactory::createFigure(FigureType::ORANGE));
    mPlayField->addFigure(FigureFactory::createFigure(FigureType::PACMAN));
    mPlayField->addFigure(FigureFactory::createFigure(FigureType::PINK));
    mPlayField->addFigure(FigureFactory::createFigure(FigureType::RED));
}


Game::~Game()
{
    delete[] mPrintBuffer;
}

void Game::Run()
{
    CStopwatch timer;
    int sum = 0;
    int deltaTime = 0;

    while (true)
    {
        Render();
        if (_kbhit()) {
            keyPressed(_getch());
            if (!FlushConsoleInputBuffer(mConsoleIn))
                cout << "FlushConsoleInputBuffer error " << GetLastError();
        }
        if (isGame) {
            timer.Start();
            mPlayField->updateFigures(static_cast<float>(deltaTime) / 1000.0f);

            Sleep(1);

            while (true)
            {
                deltaTime = timer.Now();
                if (deltaTime > 20)
                    break;
            }

            sum += deltaTime;
        }
    }
}

void Game::setWindow(const int& Width, const int& Height)
{
    _COORD coord;
    coord.X = Width + 1;
    coord.Y = Height + 1;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height;
    Rect.Right = Width - 1;

    mConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    mConsoleIn = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleScreenBufferSize(mConsole, coord);

    SetConsoleWindowInfo(mConsole, TRUE, &Rect);
}

void Game::keyPressed(const int& aKeyCode)
{
    isGame = isDirectioKey(aKeyCode);
    mPlayField->setPacManDirection(aKeyCode);

}

void Game::Render()
{
    mPrintBuffer = mPlayField->getBuffer();

    if (!WriteConsoleOutput(mConsole, mPrintBuffer, mBufferSize, mBufferCoord, &mWriteRegion)) {
        printf("WriteConsoleOutput error - (%d)\n", GetLastError());
    }
}

bool Game::isDirectioKey(int aKeyCode)
{
    bool result = false;
    switch (aKeyCode)
    {
    case PlayField::Direction::DOWN:
    case PlayField::Direction::UP:
    case PlayField::Direction::LEFT:
    case PlayField::Direction::RIGHT:
        result = true;
        break;
    default:
        break;
    }
    return result;
}

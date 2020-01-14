#include "pch.h"
#include "Game.h"
#include <assert.h>
//#include <strsafe.h>
//#include <time.h>

Game::Game() :
	cWidthSize(28)
	, cHeightSize(32)
	, isGame(true)
{
	setWindow(cWidthSize, cHeightSize);

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(mConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(mConsole, &cursorInfo);

	mChiBuffer = new CHAR_INFO[(cWidthSize + 1)*(cHeightSize + 1)];

	mDwBufferSize.X = cWidthSize * 1;
	mDwBufferSize.Y = cHeightSize * 1;		// размер буфера данных

	mDwBufferCoord.X = 0;
	mDwBufferCoord.Y = 0;				// координаты €чейки

	mLpWriteRegion.Left = 0;
	mLpWriteRegion.Top = 0;
	mLpWriteRegion.Right = cWidthSize * 1;
	mLpWriteRegion.Bottom = cHeightSize * 1;	// пр€моугольник дл€ чтени€

	mPlayField = new PlayField(cWidthSize, cHeightSize);

	mPlayField->addFigure(new PacManFigure());
	mPlayField->addFigure(new OrangeFigure());
	mPlayField->addFigure(new PinkFigure());
	mPlayField->addFigure(new CyanFigure());
	mPlayField->addFigure(new RedFigure());
}


Game::~Game()
{
}

void Game::Run()
{	
	CStopwatch timer;
	int sum = 0;
	int deltaTime = 0;
	
	while (true)
	{
		timer.Start();
		if (_kbhit()){
			keyPressed(_getch());
			if (!FlushConsoleInputBuffer(mConsoleIn))
				cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
		}

		mPlayField->moveFigures(static_cast<float>(deltaTime) / 1000.0f);
		Render();
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

void Game::setWindow(const int &Width, const int &Height)
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

void Game::keyPressed(const int &keyCode)
{
	if (isGame){
		mPlayField->setPacManDirection(keyCode);
	}
}

void Game::Render()
{
	mChiBuffer = mPlayField->getBuffer();

	if (!WriteConsoleOutput(mConsole, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion)){
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
	}
}

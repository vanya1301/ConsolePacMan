#pragma once
#include "PlayField.h"
#include <conio.h>
#include <Windows.h>
#include  "FigureFactory.h"
#include "CStopwatch.h"
#include <memory>


class Game
{
public:

    Game();
    virtual ~Game();
    void Run();

private:

    void setWindow(const int& Width, const int& Height);
    void keyPressed(const int& aKeyCode);
    void Render();
    bool isDirectioKey(int aKeyCode);
    const int cWidthSize;
    const int cHeightSize;
    bool isGame;
    HANDLE mConsole;
    HANDLE mConsoleIn;
    CHAR_INFO* mPrintBuffer;
    COORD mBufferSize;
    COORD mBufferCoord;
    SMALL_RECT mWriteRegion;
    int mGhostsSpeed;
    int mPacManSpeed;

    std::shared_ptr<PlayField>mPlayField;
};


#pragma once
#include "PlayField.h"
#include <conio.h>
#include <Windows.h>
#include  "Figures.h"
#include "CStopwatch.h"


class Game
{
public:

	Game();
	virtual ~Game();
	void Run();

private:

	void setWindow(const int &Width, const int &Height);
	void keyPressed(const int &keyCode);
	void Render();
	const int cWidthSize;
	const int cHeightSize;
	bool isGame;
	HANDLE mConsole;
	HANDLE mConsoleIn;
	CHAR_INFO* mChiBuffer;
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;
	int mGhostsSpeed;
	int mPacManSpeed;

	PlayField *mPlayField;
};


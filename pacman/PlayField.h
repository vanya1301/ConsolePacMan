#pragma once 

#include "Figures.h"
#include "Cells.h"
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;
class PlayField
{
public:

	enum Direction
	{
		DOWN = 80,
		UP = 72,
		RIGHT = 77,
		LEFT = 75
	};

	PlayField(int xSize, int ySize);

	virtual ~PlayField();
	
	void setFigurePosition(Figure * aFigure, const Position &aPosition);

	void changeDirection(Figure * aFigure, const Direction &aDirection);

	bool addFigure(Figure *aFigure);

	void moveFigures(const float &delta);

	void movePacMan(const float &delta);

	void setPacManDirection(const int &aKeyCode);
	
	int getPoints() const;

	int getLifes() const;

	CHAR_INFO* getBuffer();
	   
private:

	void fillField();

	void setCell(const Position &aPos, const wchar_t &aSymbol, const short &aColor = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	char getCellSymbol(const Position &aPosition) const;

	bool isFigureTypeExists(const Figure &aFigure) const;

	Figure* getPacMan();

	const int xSize;

	const int ySize;

	vector<Figure*> mFigures;

	int mScore;

	int mLife;

	vector<vector<Cell*>> mField;

	string mScoreStr{ "Score:" };

	CHAR_INFO* mChiBuffer;
};



#pragma once
#include "Figure.h"
class RedFigure :
	public Figure
{
public:
	RedFigure();
	virtual ~RedFigure();
	FigureDirection changeFigureDirection(const Position &aPacManPosition);
private:
	Position calculateClosestPosition(const Position &aPacManPosition);
	
};


#pragma once
#include "Figure.h"
class CyanFigure :
	public Figure
{
public:
	CyanFigure();
	virtual ~CyanFigure();
	FigureDirection changeFigureDirection(const Position &aPacManPosition);
};


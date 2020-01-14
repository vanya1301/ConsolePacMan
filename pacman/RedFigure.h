#pragma once
#include "Figure.h"
class RedFigure :
	public Figure
{
public:
	RedFigure();
	virtual ~RedFigure();
	Figure::FigureDirection changeFigureDirection();
};


#pragma once
#include "Figure.h"
class PacManFigure : public Figure
{
public:
	PacManFigure();
	~PacManFigure();
	FigureDirection changeFigureDirection();
};


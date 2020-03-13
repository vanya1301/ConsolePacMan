#pragma once
#include "Figure.h"
class OrangeFigure :
	public Figure
{
public:
	OrangeFigure();
	virtual ~OrangeFigure();
	FigureDirection changeFigureDirection(const Position &aPacManPosition);

};


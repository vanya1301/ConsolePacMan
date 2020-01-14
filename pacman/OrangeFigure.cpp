#include "pch.h"
#include "OrangeFigure.h"


OrangeFigure::OrangeFigure() : Figure(FigureType::ORANGE)
{
	mFigureColor = BACKGROUND_RED | BACKGROUND_GREEN;
	sPosition = Position(12, 14);
}


OrangeFigure::~OrangeFigure()
{
}

Figure::FigureDirection OrangeFigure::changeFigureDirection()
{
	return FigureDirection::DOWN;
}

#include "pch.h"
#include "PinkFigure.h"


PinkFigure::PinkFigure() : Figure(FigureType::PINK)
{
	mFigureColor = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE;
	sPosition = Position(14, 14);
}


PinkFigure::~PinkFigure()
{
}

Figure::FigureDirection PinkFigure::changeFigureDirection()
{
	return FigureDirection::DOWN;
}

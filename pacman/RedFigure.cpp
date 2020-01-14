#include "pch.h"
#include "RedFigure.h"


RedFigure::RedFigure() : Figure(FigureType::RED)
{
	mFigureColor = BACKGROUND_RED;
	sPosition = Position(13, 14);
}


RedFigure::~RedFigure()
{
}

Figure::FigureDirection RedFigure::changeFigureDirection()
{
	return FigureDirection::DOWN;
}

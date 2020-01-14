#include "pch.h"
#include "CyanFigure.h"


CyanFigure::CyanFigure() :
	Figure(Figure::FigureType::CYAN)

{
	mFigureColor = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;
	sPosition = Position(11, 14);

}


CyanFigure::~CyanFigure()
{
}

Figure::FigureDirection CyanFigure::changeFigureDirection()
{
	return FigureDirection::DOWN;
}

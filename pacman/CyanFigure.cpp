#include "pch.h"
#include "CyanFigure.h"


CyanFigure::CyanFigure() :
    Figure(FigureType::CYAN)

{
    mFigureColor = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;
    sPosition = Position(14, 15);

}


CyanFigure::~CyanFigure()
{
}

FigureDirection CyanFigure::changeFigureDirection(const Position& aPacManPosition)
{
    return FigureDirection::NONE;
}

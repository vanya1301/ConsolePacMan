#include "pch.h"
#include "PinkFigure.h"


PinkFigure::PinkFigure() : Figure(FigureType::PINK
    , Position(14, 14)
    , BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE)
{
}

FigureDirection PinkFigure::changeFigureDirection(const Position& aPacManPosition)
{
    FigureDirection result = FigureDirection::NONE;

    setCurrentDirection(result);
    return result;
}

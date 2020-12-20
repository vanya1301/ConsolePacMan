#include "pch.h"
#include "PacManFigure.h"


PacManFigure::PacManFigure() :
    Figure(FigureType::PACMAN)
{
    mFigureColor = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;
    sPosition = Position(14, 23);
}


PacManFigure::~PacManFigure()
{
}

FigureDirection PacManFigure::changeFigureDirection(const Position& aPacManPosition)
{
    return FigureDirection::DOWN;
}


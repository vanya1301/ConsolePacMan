#include "pch.h"
#include "PacManFigure.h"


PacManFigure::PacManFigure() :
    Figure(FigureType::PACMAN
        , Position(14, 23)
        , BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN)
{
}

FigureDirection PacManFigure::changeFigureDirection(const Position& aPacManPosition)
{
    return FigureDirection::DOWN;
}


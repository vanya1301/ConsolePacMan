#include "pch.h"
#include "OrangeFigure.h"


OrangeFigure::OrangeFigure() : Figure(FigureType::ORANGE)
{
    mFigureColor = BACKGROUND_RED | BACKGROUND_GREEN;
    sPosition = Position(13, 15);
}


OrangeFigure::~OrangeFigure()
{
}

FigureDirection OrangeFigure::changeFigureDirection(const Position& aPacManPosition)
{
    return FigureDirection::NONE;
}

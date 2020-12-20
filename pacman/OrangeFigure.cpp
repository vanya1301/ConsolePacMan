#include "pch.h"
#include "OrangeFigure.h"


OrangeFigure::OrangeFigure() : Figure(FigureType::ORANGE
    , Position(13, 15)
    , BACKGROUND_RED | BACKGROUND_GREEN)
{
}


OrangeFigure::~OrangeFigure()
{
}

FigureDirection OrangeFigure::changeFigureDirection(const Position& aPacManPosition)
{
    return FigureDirection::NONE;
}

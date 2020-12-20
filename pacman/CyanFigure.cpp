#include "pch.h"
#include "CyanFigure.h"


CyanFigure::CyanFigure() :
    Figure(FigureType::CYAN
        , Position(14, 15)
        , BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE)

{
}


CyanFigure::~CyanFigure()
{
}

FigureDirection CyanFigure::changeFigureDirection(const Position& aPacManPosition)
{
    return FigureDirection::NONE;
}

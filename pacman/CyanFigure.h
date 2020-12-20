#pragma once
#include "Figure.h"
class CyanFigure :
    public Figure
{
public:
    CyanFigure();
    virtual ~CyanFigure() = default;
    FigureDirection changeFigureDirection(const Position& aPacManPosition) override;
};


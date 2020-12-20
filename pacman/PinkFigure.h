#pragma once
#include "Figure.h"
class PinkFigure :
    public Figure
{
public:
    PinkFigure();
    virtual ~PinkFigure() = default;
    FigureDirection changeFigureDirection(const Position& aPacManPosition) override;
};


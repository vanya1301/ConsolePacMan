#pragma once
#include "Figure.h"
class OrangeFigure :
    public Figure
{
public:
    OrangeFigure();
    virtual ~OrangeFigure() = default;
    FigureDirection changeFigureDirection(const Position& aPacManPosition) override;
};


#pragma once
#include "Figure.h"
class RedFigure :
    public Figure
{
public:
    RedFigure();
    virtual ~RedFigure() = default;
    FigureDirection changeFigureDirection(const Position& aPacManPosition) override;
private:
    Position calculateClosestPosition(const Position& aPacManPosition);

};


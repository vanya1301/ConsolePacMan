#pragma once
#include "Figure.h"
class PacManFigure : public Figure
{
public:
    PacManFigure();
    ~PacManFigure();
    void setNextDirection(const FigureDirection& aDirection);
private:
    FigureDirection changeFigureDirection(const Position& aPacManPosition);

    FigureDirection mNextDirection;
};


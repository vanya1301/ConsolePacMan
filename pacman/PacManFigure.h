#pragma once
#include "Figure.h"
class PacManFigure : public Figure
{
public:
    PacManFigure();
    ~PacManFigure() = default;
    void setNextDirection(const FigureDirection& aDirection);
private:
    FigureDirection changeFigureDirection(const Position& aPacManPosition) override;

    FigureDirection mNextDirection;
};


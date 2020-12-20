#include "pch.h"
#include "Figure.h"
#include "cmath"


Figure::Figure(const FigureType& type, const Position& figurePos, short figureColor) :
    mFigureType(type)
    , sPos(figurePos)
    , mFigureColor(figureColor)
    , mMoveDirection(FigureDirection::NONE)
    , mNextDirection(FigureDirection::NONE)
{
}

Position Figure::getPosition() const
{
    return sPos;
}

FigureType Figure::getType() const
{
    return mFigureType;
}

short Figure::getFigureColor() const
{
    return mFigureColor;
}

void Figure::setPosition(const Position& aPosition)
{
    sPos = aPosition;
}

void Figure::setCurrentDirection(const FigureDirection& aDirection)
{
    if (aDirection != FigureDirection::NONE)
        mMoveDirection = aDirection;
}

void Figure::setNextDirection(const FigureDirection& aDirection)
{
    mNextDirection = aDirection;
}

float Figure::destination(const Position& p1, const Position& p2)
{
    return abs(sqrtf(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
}

FigureDirection Figure::getCurrentDirection() const
{
    return mMoveDirection;
}

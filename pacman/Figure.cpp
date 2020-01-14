#include "pch.h"
#include "Figure.h"


Figure::Figure(FigureType type) :
	mFigureType(type)
{
}

Figure::~Figure()
{
}

Position Figure::getPosition() const
{
	return sPosition;
}

Figure::FigureType Figure::getType() const
{
	return mFigureType;
}

short Figure::getFigureColor() const
{
	return mFigureColor;
}

void Figure::setPosition(const Position &aPosition)
{
	sPosition = aPosition;
}

void Figure::setCurrentDirection(const FigureDirection & aDirection)
{
	mMoveDirection = aDirection;
}

void Figure::setNextDirection(const FigureDirection & aDirection)
{
	mNextDirection = aDirection;
}

Figure::FigureDirection Figure::getCurrentDirection() const
{
	return mMoveDirection;
}

#include "pch.h"
#include "Figure.h"
#include "cmath"


Figure::Figure(const FigureType &type) :
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

FigureType Figure::getType() const
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

void Figure::setCurrentDirection(const FigureDirection &aDirection)
{
	if (aDirection != FigureDirection::NONE) {
		mMoveDirection = aDirection;
	}
}

void Figure::setNextDirection(const FigureDirection & aDirection)
{
	mNextDirection = aDirection;
}

float Figure::destination(const Position & p1, const Position & p2)
{
	float result = 0.0f;
	result = abs(sqrtf(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
	return result;
}

FigureDirection Figure::getCurrentDirection() const
{
	return mMoveDirection;
}

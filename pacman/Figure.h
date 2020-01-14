#pragma once
#include <Windows.h>
struct Position
{
	Position(int xPos = -1, int yPos = -1) :
		x(xPos)
		, y(yPos)
	{}

	int x;
	int y;
};

class Figure
{
public:
	enum class FigureType
	{
		PACMAN
		, RED
		, CYAN
		, PINK
		, ORANGE
	};

	enum class FigureDirection
	{
		UP
		, DOWN
		, RIGHT
		, LEFT
	};
		
	Figure(FigureType type);
	virtual ~Figure();

	Position getPosition() const;
	FigureType getType() const;
	short getFigureColor() const;
	FigureDirection getCurrentDirection() const;
	virtual FigureDirection changeFigureDirection() = 0;
	virtual void setPosition(const Position &aPosition);
	void setCurrentDirection(const FigureDirection &aDirection);
	void setNextDirection(const FigureDirection &aDirection);

protected:
	Position sPosition;
	const FigureType mFigureType;
	short mFigureColor;
	FigureDirection mMoveDirection; 
	FigureDirection mNextDirection;
};
#pragma once
#include <Windows.h>
struct Position
{
	Position(int xPos = -1, int yPos = -1) :
		x(xPos)
		, y(yPos)
	{}
	friend bool operator==(const Position &p1, const Position &p2)
	{
		return (p1.x == p2.x&&p1.y == p2.y);
	}
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
		, NONE
	};

	Figure(const FigureType &type);
	virtual ~Figure();

	Position getPosition() const;

	FigureType getType() const;

	short getFigureColor() const;

	FigureDirection getCurrentDirection() const;

	virtual FigureDirection changeFigureDirection(const Position &aPacManPosition) = 0;

	virtual void setPosition(const Position &aPosition);

	void setCurrentDirection(const FigureDirection &aDirection);

	void setNextDirection(const FigureDirection &aDirection);

protected:
	float destination(const Position &p1, const Position &p2);
	Position sPosition;
	const FigureType mFigureType;
	short mFigureColor;
	FigureDirection mMoveDirection;
	FigureDirection mNextDirection;
};

typedef Figure::FigureDirection FigureDirection;
typedef Figure::FigureType FigureType;
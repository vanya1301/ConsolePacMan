#include "pch.h"
#include "RedFigure.h"


RedFigure::RedFigure() : Figure(FigureType::RED, Position(13, 11), BACKGROUND_RED)
{
}


RedFigure::~RedFigure()
{
}

FigureDirection RedFigure::changeFigureDirection(const Position& aPacManPosition)
{
    FigureDirection result = FigureDirection::NONE;

    float dest = 10000.0f;

    if (destination(Position(aPacManPosition.x + 1, aPacManPosition.y), sPosition) < dest) {
        dest = destination(Position(aPacManPosition.x + 1, aPacManPosition.y), sPosition);
        result = FigureDirection::RIGHT;
    }

    if (destination(Position(aPacManPosition.x - 1, aPacManPosition.y), sPosition) < dest) {
        dest = destination(Position(aPacManPosition.x - 1, aPacManPosition.y), sPosition);
        result = FigureDirection::LEFT;
    }

    if (destination(Position(aPacManPosition.x, aPacManPosition.y + 1), sPosition) < dest) {
        dest = destination(Position(aPacManPosition.x, aPacManPosition.y + 1), sPosition);
        result = FigureDirection::UP;
    }

    if (destination(Position(aPacManPosition.x, aPacManPosition.y - 1), sPosition) < dest) {
        dest = destination(Position(aPacManPosition.x, aPacManPosition.y - 1), sPosition);
        result = FigureDirection::DOWN;
    }

    setCurrentDirection(result);
    return result;
}

Position RedFigure::calculateClosestPosition(const Position& aPacManPosition)
{
    float dest = 10000.0f;

    if (destination(Position(aPacManPosition.x + 1, aPacManPosition.y), sPosition) < dest)
        dest = destination(Position(aPacManPosition.x + 1, aPacManPosition.y), sPosition);

    if (destination(Position(aPacManPosition.x - 1, aPacManPosition.y), sPosition) < dest)
        dest = destination(Position(aPacManPosition.x - 1, aPacManPosition.y), sPosition);

    if (destination(Position(aPacManPosition.x, aPacManPosition.y + 1), sPosition) < dest)
        dest = destination(Position(aPacManPosition.x, aPacManPosition.y + 1), sPosition);

    if (destination(Position(aPacManPosition.x + 1, aPacManPosition.y - 1), sPosition) < dest)
        dest = destination(Position(aPacManPosition.x, aPacManPosition.y - 1), sPosition);

    return dest;
}

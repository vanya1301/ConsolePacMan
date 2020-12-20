#include "pch.h"
#include "RedFigure.h"
#include <map>
#include <vector>
#include <limits>


RedFigure::RedFigure() : Figure(FigureType::RED, Position(13, 11), BACKGROUND_RED)
{
    // TODO: у фигуры нет начального движения,
    // и фигура выбирает направление не опираясь на доступные для хода клетки
    mMoveDirection = FigureDirection::RIGHT;
}

FigureDirection RedFigure::changeFigureDirection(const Position& aPacManPos)
{
    FigureDirection result = FigureDirection::NONE;
    std::map<FigureDirection, float> distances;
    distances[FigureDirection::RIGHT] = destination(Position(aPacManPos.x + 1, aPacManPos.y), sPos);
    distances[FigureDirection::LEFT] = destination(Position(aPacManPos.x - 1, aPacManPos.y), sPos);
    distances[FigureDirection::UP] = destination(Position(aPacManPos.x, aPacManPos.y + 1), sPos);
    distances[FigureDirection::DOWN] = destination(Position(aPacManPos.x, aPacManPos.y - 1), sPos);

    float minDist = FLT_MAX;

    for (const auto& item : distances)
        if (item.second < minDist) {
            minDist = item.second;
            result = item.first;
        }
    setCurrentDirection(result);
    return result;
}
 

Position RedFigure::calculateClosestPosition(const Position& aPacManPosition)
{
    using namespace std;
    std::vector<float> distances = {
    destination(Position(aPacManPosition.x + 1, aPacManPosition.y), sPos)
    ,destination(Position(aPacManPosition.x - 1, aPacManPosition.y), sPos)
    ,destination(Position(aPacManPosition.x, aPacManPosition.y + 1), sPos)
    ,destination(Position(aPacManPosition.x + 1, aPacManPosition.y - 1), sPos) };
    float minDist = FLT_MAX;

    for (const auto& item : distances)
        if (item < minDist)
            minDist = item;

    return minDist;
}

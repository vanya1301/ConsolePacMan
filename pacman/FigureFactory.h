#pragma once

#include "OrangeFigure.h"
#include "PacManFigure.h"
#include "PinkFigure.h"
#include "RedFigure.h"
#include "CyanFigure.h"
#include <memory>

class FigureFactory
{
public:
    static std::shared_ptr<Figure> createFigure(const FigureType& aType)
    {
        std::shared_ptr<Figure> result = nullptr;
        switch (aType)
        {
        case FigureType::CYAN:
            result = std::make_shared<CyanFigure>();
            break;
        case FigureType::ORANGE:
            result = std::make_shared<OrangeFigure>();
            break;
        case FigureType::PACMAN:
            result = std::make_shared<PacManFigure>();
            break;
        case FigureType::PINK:
            result = std::make_shared<PinkFigure>();
            break;
        case FigureType::RED:
            result = std::make_shared<RedFigure>();
            break;
        default:
            break;
        }
        return result;
    }
private:
    virtual ~FigureFactory() {}
};
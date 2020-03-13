#pragma once

#include "OrangeFigure.h"
#include "PacManFigure.h"
#include "PinkFigure.h"
#include "RedFigure.h"
#include "CyanFigure.h"

class FigureFactory
{
public:
	static Figure* createFigure(const FigureType &aType)
	{
		Figure *result = nullptr;
		switch (aType)
		{
		case FigureType::CYAN:
			result = new CyanFigure();
			break;
		case FigureType::ORANGE:
			result = new OrangeFigure();
			break;
		case FigureType::PACMAN:
			result = new PacManFigure();
			break;
		case FigureType::PINK:
			result = new PinkFigure();
			break;
		case FigureType::RED:
			result = new RedFigure();
			break;
		default:
			break;
		}
		return result;
	}
private:
	virtual ~FigureFactory() {}
};
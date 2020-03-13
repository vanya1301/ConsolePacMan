#include "pch.h"
#include "PlayField.h"



PlayField::PlayField(int xSize, int ySize) :
	xSize(xSize)
	, ySize(ySize)
{
	mChiBuffer = new CHAR_INFO[xSize * ySize];
	fillField();
}

PlayField::~PlayField()
{
	delete[] mChiBuffer;
	for (auto a : mFigures)
	{
		delete a;
	}
}

void PlayField::fillField()
{
	for (size_t i = 0; i < ySize; i++)
	{
		for (size_t j = 0; j < xSize; j++)
		{
			if (i == ySize - 1 && j < mScoreStr.size())
			{
				setCell(Position(j, i), mScoreStr[j]);
				continue;
			}

			switch (mLabyrinthMap[i][j])
			{
			case '0':
				setCell(Position(j, i), 'x', BACKGROUND_INTENSITY);
				break;
			case '.':
				setCell(Position(j, i), '.');
				break;
			case '#':
				setCell(Position(j, i), ' ');
				mJailCells.push_back(Position(j, i));
				break;
			case ' ':
				setCell(Position(j, i), ' ');
				break;
			case'd':
				setCell(Position(j, i), '.');
				mDecidingCells.push_back(Position(j, i));
				break;
			default:
				setCell(Position(j, i), '*', BACKGROUND_INTENSITY | BACKGROUND_RED);
				break;
			}
		}

	}
}

void PlayField::setCell(const Position & aPos, const wchar_t & aSymbol, const short &aColor)
{
	mChiBuffer[aPos.x + xSize * aPos.y].Char.UnicodeChar = aSymbol;
	mChiBuffer[aPos.x + xSize * aPos.y].Attributes = aColor;
}

char PlayField::getCellSymbol(const Position &aPosition) const
{
	return mChiBuffer[aPosition.x + xSize * aPosition.y].Char.AsciiChar;
}

bool PlayField::isFigureTypeExists(const Figure & aFigure) const
{
	bool result = false;
	for (const auto& figure : mFigures)
	{
		if (figure->getType() == aFigure.getType()) {
			result = true;
			break;
		}
	}
	return result;
}

bool PlayField::isJailCell(const Position & aPosition) const
{
	bool result = false;
	for (const auto &cell : mJailCells)
	{
		if (cell == aPosition)
			result = true;
	}
	return result;
}

bool PlayField::isDecidingCell(const Position & aPosition) const
{
	bool result = false;
	for (const auto &cellPos : mDecidingCells)
	{
		if (cellPos == aPosition)
		{
			result = true;
		}
	}
	return result;
}

Figure * PlayField::getPacMan()
{
	Figure *result = nullptr;
	for (const auto& figure : mFigures)
	{
		if (figure->getType() == FigureType::PACMAN) {
			result = figure;
			break;
		}
	}
	return result;
}

void PlayField::setPacManDirection(const int &aKeyCode)
{
	auto pacMan = getPacMan();
	auto pacManPos = pacMan->getPosition();

	FigureDirection direction = pacMan->getCurrentDirection();
	switch (aKeyCode) {
	case Direction::DOWN:
		direction = FigureDirection::DOWN;
		pacManPos.y++;
		break;
	case Direction::UP:
		direction = FigureDirection::UP;
		pacManPos.y--;
		break;
	case Direction::RIGHT:
		direction = FigureDirection::RIGHT;
		pacManPos.x++;
		break;
	case Direction::LEFT:
		direction = FigureDirection::LEFT;
		pacManPos.x--;
		break;
	default:
		break;
	}

	if (getCellSymbol(pacManPos) != 'x' && !isJailCell(pacManPos)) {
		pacMan->setCurrentDirection(direction);
	}
	else {
		pacMan->setNextDirection(direction);
	}
}

void PlayField::setFigurePosition(Figure * aFigure, const Position &aPosition)
{
	if (aFigure != nullptr) {
		for (const auto &figure : mFigures)
		{
			if (aFigure == figure) {

				if (getCellSymbol(aPosition) != 'x' && !isJailCell(aPosition)) {
					setCell(figure->getPosition(), ' ');
					setCell(aPosition, ' ', aFigure->getFigureColor());
					aFigure->setPosition(aPosition);
				}
				break;
			}
		}
	}

}

bool PlayField::addFigure(Figure *aFigure)
{
	bool result = false;
	if (aFigure != nullptr) {
		auto figurePos = aFigure->getPosition();
		auto figureColor = aFigure->getFigureColor();

		if (!isFigureTypeExists(*aFigure)) {
			setCell(figurePos, ' ', figureColor);
			mFigures.push_back(aFigure);
			result = true;
		}
	}
	return result;
}

void PlayField::updateFigures(const float &delta)
{
	movePacMan(delta);
	moveGhosts(delta);
}

void PlayField::movePacMan(const float &delta)
{
	static float waiter = 0;
	waiter += delta;
	if (waiter > 0.2) {
		auto pacMan = getPacMan();
		auto pacManDirection = pacMan->getCurrentDirection();
		auto pacManPos = pacMan->getPosition();

		moveFigure(pacMan);

		switch (getCellSymbol(pacManPos))
		{
		case '.':
			mScore++;
			break;
		case '*':
			mScore += 2;
			break;
		default:
			break;
		}

		waiter = 0;
	}
}

void PlayField::moveGhosts(const float & delta)
{
	static float waiter = 0;
	auto pacMan = getPacMan();
	FigureDirection figureDirection;
	waiter += delta;
	if (waiter > 0.15) {
		for (auto &ghost : mFigures)
		{
			if (ghost->getType() != FigureType::PACMAN) {
				if (isDecidingCell(ghost->getPosition())) {
					ghost->changeFigureDirection(pacMan->getPosition());
				}
				moveFigure(ghost);
				waiter = 0;
			}
		}
	}
}

void PlayField::moveFigure(Figure * figure)
{
	auto figureDirection = figure->getCurrentDirection();
	auto figurePos = figure->getPosition();
	switch (figureDirection)
	{
	case FigureDirection::UP:
		figurePos.y--;
		break;
	case FigureDirection::DOWN:
		figurePos.y++;
		break;
	case FigureDirection::RIGHT:
		figurePos.x++;
		break;
	case FigureDirection::LEFT:
		figurePos.x--;
		break;
	default:
		break;
	}
	setFigurePosition(figure, figurePos);
}

CHAR_INFO * PlayField::getBuffer()
{
	return mChiBuffer;
}

int PlayField::getPoints() const
{
	return mScore;
}

int PlayField::getLifes() const
{
	return mLife;
}



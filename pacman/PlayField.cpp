#include "pch.h"
#include "PlayField.h"
#include "FieldLabyrinth.h"


PlayField::PlayField(int xSize, int ySize) :
	xSize(xSize)
	, ySize(ySize)
{
	mChiBuffer = new CHAR_INFO[xSize * ySize];
	fillField();
}

void PlayField::fillField()
{
	for (int i = 0; i < ySize; i++)
	{
		for (int j = 0; j < xSize; j++)
		{
			if (i == ySize - 1 && j < mScoreStr.size())
			{
				setCell(Position(j, i), mScoreStr[j]);
				continue;
			}

			switch (map[i][j])
			{
			case '0':
				setCell(Position(j, i), 'x', BACKGROUND_INTENSITY);
				break;
			case '.':
				setCell(Position(j, i), '.');
				break;
			case '#':
				setCell(Position(j, i), ' ');
				break;
			case ' ':
				setCell(Position(j, i), ' ');
				break;
			default:
				setCell(Position(j, i), '*', BACKGROUND_INTENSITY | BACKGROUND_RED);
				break;
			}
		}
		
	}
	//for (int i = 0; i < map.size(); i++)
	//{
	//	mField.push_back(vector<Cell*>());
	//	for (int j = 0; j < map[i].size(); j++)
	//	{
	//		switch (map[i][j])
	//		{
	//		case '0':
	//			mField[i].push_back(new BarierCell());
	//			mChiBuffer[j + map[i].size()*i].Char.UnicodeChar = 'X';
	//			break;
	//		case '.':
	//			mField[i].push_back(new PlayCell());
	//			mChiBuffer[j + map[i].size()*i].Char.UnicodeChar = '.';
	//			break;
	//		case '#':
	//			mField[i].push_back(new JailCell());
	//			mChiBuffer[j + map[i].size()*i].Char.UnicodeChar = ' ';
	//			break;
	//		default:
	//			mField[i].push_back(new PlayCell());
	//			mChiBuffer[j + map[i].size()*i].Char.UnicodeChar = '.';
	//			break;
	//		}
	//		mChiBuffer[j + map[i].size()*i].Attributes = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED;
	//	}
	//}
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

Figure * PlayField::getPacMan()
{
	Figure *result = nullptr;
	for (const auto& figure : mFigures)
	{
		if (figure->getType() == Figure::FigureType::PACMAN) {
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

	Figure::FigureDirection direction;
	switch (aKeyCode) {
	case Direction::DOWN:
		direction = Figure::FigureDirection::DOWN;
		pacManPos.y++;
		break;
	case Direction::UP:
		direction = Figure::FigureDirection::UP;
		pacManPos.y--;
		break;
	case Direction::RIGHT:
		direction = Figure::FigureDirection::RIGHT;
		pacManPos.x++;
		break;
	case Direction::LEFT:
		direction = Figure::FigureDirection::LEFT;
		pacManPos.x--;
		break;
	default:
		return;
		break;
	}

	if (getCellSymbol(pacManPos) != 'x') {
		pacMan->setCurrentDirection(direction);
	}
	else {
	pacMan->setNextDirection(direction);
	}
}


void PlayField::setFigurePosition(Figure * aFigure, const Position &aPosition)
{
	for (const auto &figure : mFigures)
	{
		if (aFigure == figure) {
			
			if (getCellSymbol(aPosition) != 'x') {
				setCell(figure->getPosition(), ' ');
				setCell(aPosition, ' ', aFigure->getFigureColor());
				aFigure->setPosition(aPosition);
			}
			break;
		}
	}

}

void PlayField::changeDirection(Figure * aFigure, const Direction &aDirection)
{
	for (const auto &figure : mFigures)
	{
		if (figure == aFigure) {

		}
	}
}

bool PlayField::addFigure(Figure *aFigure)
{
	bool result = false;
	auto figurePos = aFigure->getPosition();
	auto figureColor = aFigure->getFigureColor();

	if (!isFigureTypeExists(*aFigure)) {
		setCell(figurePos, ' ', figureColor);
		mFigures.push_back(aFigure);
		result = true;
	}
	return result;

}

void PlayField::moveFigures(const float &delta)
{
	movePacMan(delta);
}

void PlayField::movePacMan(const float &delta)
{
	static float waiter = 0;
	waiter += delta;
	if (waiter > 0.2) {
		auto pacMan = getPacMan();
		auto pacManDirection = pacMan->getCurrentDirection();
		auto pacManPos = pacMan->getPosition();
		switch (pacManDirection)
		{
		case Figure::FigureDirection::UP:
			pacManPos.y--;
			break;
		case Figure::FigureDirection::DOWN:
			pacManPos.y++;
			break;
		case Figure::FigureDirection::RIGHT:
			pacManPos.x++;
			break;
		case Figure::FigureDirection::LEFT:
			pacManPos.x--;
			break;
		default:
			return;
			break;
		}
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
		setFigurePosition(pacMan, pacManPos);
		waiter = 0;
	}
}

CHAR_INFO * PlayField::getBuffer()
{
	return mChiBuffer;
}

int PlayField::getPoints()
{
	return mScore;
}

int PlayField::getLifes()
{
	return mLife;
}

PlayField::~PlayField()
{
}

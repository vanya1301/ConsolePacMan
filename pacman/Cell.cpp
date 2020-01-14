#include "pch.h"
#include "Cell.h"


Cell::Cell(CellType cellType):
	mCellType(cellType)
{
	switch (mCellType)
	{
	case Cell::CellType::PlayCell:
		mCellSymbol.Char.UnicodeChar = '.';
		break;
	case Cell::CellType::Barier:
		mCellSymbol.Char.UnicodeChar = 'X';
		break;
	case Cell::CellType::Jail:
		mCellSymbol.Char.UnicodeChar = ' ';
		break;
	default:
		break;
	}
}

char Cell::getCellSymbol()
{
	return mCellSymbol.Char.UnicodeChar;
}

Cell::CellType Cell::getCellType()
{
	return mCellType;
}

Cell::~Cell()
{
}

#pragma once
#include "Windows.h"
class Cell
{
public:
	enum class CellType
	{
		PlayCell
		, Barier
		, Jail
	};
	Cell(CellType cellType);
	char getCellSymbol();
	CellType getCellType();
	virtual ~Cell();

protected:
	CellType mCellType;
	CHAR_INFO mCellSymbol;
};


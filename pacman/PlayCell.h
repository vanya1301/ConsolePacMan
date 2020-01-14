#pragma once
#include "Cell.h"
class PlayCell :
	public Cell
{
public:
	PlayCell();
	virtual ~PlayCell();
	bool isFoodInCell;


};


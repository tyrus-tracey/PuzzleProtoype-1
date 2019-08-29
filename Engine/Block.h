#pragma once
#include "Colors.h"
#include "Location.h"
class Board;
class Block
{
public:
	Block(Board &board);
	~Block();
	Color getColor() const;
	void draw() const;
	void operator++();
private:
	Board &brd;
	Color c;
	Location loc;
	Location direction;
};


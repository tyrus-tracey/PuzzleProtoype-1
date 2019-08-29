#pragma once
#include "Board.h"
#include "Graphics.h"

class Player
{
public:
	Player(Graphics & gfx);
	~Player();
	Board * getBoard();
private:
	Board board;
	Graphics & gfx;
};


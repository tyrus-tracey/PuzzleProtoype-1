#pragma once
#include "Board.h"
#include "Graphics.h"
#include "Chain.h"

class Player
{
public:
	Player(Graphics & gfx);
	~Player();
	Chain * getChain();
	Board * getBoard();
private:
	Board board;
	Graphics & gfx;
	Chain * pChain;
};


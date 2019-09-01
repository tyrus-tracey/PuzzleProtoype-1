#include "Player.h"



Player::Player(Graphics & gfx)
	:
board(gfx), gfx(gfx)
{
	pChain = new Chain(board);
}


Player::~Player()
{
}

Chain * Player::getChain()
{
	return pChain;
}

Board * Player::getBoard() 
{
	return &board;
}

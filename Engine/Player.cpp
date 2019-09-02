#include "Player.h"



Player::Player(Graphics & gfx)
	:
board(gfx), gfx(gfx)
{
	pChain = new Chain(board);
}


Player::~Player()
{
	delete pChain;
}

Chain * Player::getChain()
{
	return pChain;
}

Board * Player::getBoard() 
{
	return &board;
}

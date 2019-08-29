#include "Player.h"



Player::Player(Graphics & gfx)
	:
board(gfx), gfx(gfx)
{
}


Player::~Player()
{
}

Board * Player::getBoard() 
{
	return &board;
}

#include "Chain.h"
#include <cstdlib>
#include <time.h>

Chain::Chain(Board& board)
	:
brd(board)
{
}

Chain::~Chain()
{
}

void Chain::drawBlock(Block & block)
{
	brd.drawCell(block.loc, block.c);
}

Color Chain::Block::getColor() const
{
	return c;
}

void Chain::Block::initializeColor()
{
	const int rng = rand() % 4;
	switch (rng) {
	case 0:
		c = Colors::Red;
		break;
	case 1:
		c = Colors::Green;
		break;
	case 2:
		c = Colors::Blue;
		break;
	case 3:
		c = Colors::Yellow;
		break;
	default:
		c = Colors::Red;
		break;
	}
}

void Chain::Block::initializeLocation(Board &board)
{
	loc = Location(board.getWidth() - board.scale, board.getScale());
	direction = Location(-1, 0);
}

//if the middle pixel of the next cell in the direction of this block is grey,
//	turn block 90 degrees CCW
//move this block by adding direction onto it
void Chain::moveBlock(Block &block)
{
	const Color WALLCOLOR = Colors::Gray;
	if ((brd.getGfx().getPixel(getMidPoint(block) + (block.direction * brd.scale))) == WALLCOLOR) {
		if (block.direction.X() == 0) {
			block.direction.setX(block.direction.Y());
			block.direction.setY(0);
		}
		else if (block.direction.X() == -1) {
			block.direction.setX(0);
			block.direction.setY(1);
		}
		else {
			block.direction.setX(0);
			block.direction.setY(-1);
		}
	}
	Location offset;
	offset.setX(block.direction.X() * brd.scale);
	offset.setY(block.direction.Y() * brd.scale);
	block.loc = block.loc + offset;
}

//Returns mid-point location of block, rather than the actual location (top-left corner)
Location Chain::getMidPoint(Block &block) const
{
	Location output(int(block.loc.X() + float((0.5 * brd.scale))), int(block.loc.Y() + float((0.5 * brd.scale))));
	return output;
}

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

//Create a block of random color and set it behind the opening, and set it default facing left
Chain::Block::Block(Board &board)
	:
	B_brd(board)
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
	int test = B_brd.getWidth();
	loc = Location(B_brd.getWidth() - B_brd.scale, B_brd.getScale());
	direction = Location(-1, 0);
}


Chain::Block::~Block()
{
}

Color Chain::Block::getColor() const
{
	return c;
}

void Chain::Block::draw() const
{
	B_brd.drawCell(loc.X(), loc.Y(), c);
	//brd.drawCell(loc, c);
}

//if the middle pixel of the next cell in the direction of this block is grey,
//	turn block 90 degrees CCW
//move this block by adding direction onto it
void Chain::Block::operator++()
{
	const Color WALLCOLOR = Colors::Gray;
	if ((B_brd.getGfx().getPixel(operator*() + (direction * B_brd.scale))) == WALLCOLOR) {
		if (direction.X() == 0) {
			direction.setX(direction.Y());
			direction.setY(0);
		}
		else if (direction.X() == -1) {
			direction.setX(0);
			direction.setY(1);
		}
		else {
			direction.setX(0);
			direction.setY(-1);
		}
	}
	Location offset;
	offset.setX(direction.X() * B_brd.scale);
	offset.setY(direction.Y() * B_brd.scale);
	loc = loc + offset;
}

//Returns mid-point location of block, rather than the actual location (top-left corner)
Location Chain::Block::operator*() const
{
	Location output(int(loc.X() + float((0.5 * B_brd.scale))), int(loc.Y() + float((0.5 * B_brd.scale))));
	return output;
}

#include "Block.h"
#include "Board.h"
#include <cstdlib>
#include <time.h>

//Create a block of random color and set it behind the opening, and set it default facing left
Block::Block(Board &board)
	:
	brd(board)
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
	loc = Location(board.getWidth() - board.scale, board.getScale());
	direction = Location(-1, 0);
}


Block::~Block()
{
}

Color Block::getColor() const
{
	return c;
}

void Block::draw() const
{
	brd.drawCell(loc.X(), loc.Y(), c);
	//brd.drawCell(loc, c);
}

//if the next cell is a wall (gray color), set direction 90 degrees
//move this block by adding direction onto it
void Block::operator++()
{
	const Color WALLCOLOR = Colors::Gray;
	if ( brd.getGfx().getPixel((loc + direction)) == WALLCOLOR ) {
		if (direction.X() == 0) {
			direction.setX(direction.Y());
			direction.setY(0);
		}
		else if (direction.X() == -1){
			direction.setX(0);
			direction.setY(1);
		}
		else {
			direction.setX(0);
			direction.setY(-1);
		}
	}
	Location offset;
	offset.setX(direction.X() * brd.scale);
	offset.setY(direction.Y() * brd.scale);
	loc = loc + offset;
}

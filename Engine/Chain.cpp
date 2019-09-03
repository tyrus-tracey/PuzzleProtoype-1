#include "Chain.h"
#include <cstdlib>
#include <time.h>

Chain::Chain(Board& board)
	:
brd(board)
{
	blocks = new Block;
	blocks->initialize(brd);
	if (size == 0) {
		HEAD = blocks;
		TAIL = blocks;
	}
	size = 1;
}

Chain::~Chain()
{
	unlinkChain(HEAD, TAIL);
	delete HEAD;
	delete TAIL;
}

void Chain::drawChain()
{
	Block * blockptr = HEAD;
	for (int i = 0; i < size; i++) {
		drawBlock(blockptr);
		blockptr = blockptr->next;
	}
}

void Chain::moveChain()
{
	Block * blockptr = HEAD;
	for (int i = 0; i < size; i++) {
		moveBlock(blockptr);
		blockptr = blockptr->next;
	}
}

void Chain::growChain()
{
	Block * newBlock = new Block;
	newBlock->initialize(brd);
	TAIL->next = newBlock;
	newBlock->prev = TAIL;
	TAIL = newBlock;
	size++;
}

//Delete all blocks between A and B and attach A to B
//B MUST be ahead of A.
void Chain::unlinkChain(Block * blockA, Block * blockB)
{
	Block * blockptr = blockA->next;
	while (blockptr != blockB) {
		blockptr = blockptr->next;
		delete blockptr->prev;
	}
	blockA->next = blockB;
	blockB->prev = blockA;
}

bool Chain::overThreshold() const
{
	Location middleOfBoard(brd.getWidth() / 2, brd.getHeight() / 2);
	if (getMidPoint(HEAD) == middleOfBoard) {
		return true;
	}
	return false;
}

void Chain::drawBlock(Block * block) const
{
	brd.drawCell(block->loc, block->c);
}

Color Chain::Block::getColor() const
{
	return c;
}

//High-level function to create a block
void Chain::Block::initialize(Board &board)
{
	initializeColor();
	initializeLocation(board);
	//TODO: set pointers
}

//Set a random block color
//TODO: Improve randomization distribution by using std::md19337 or whatever
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

//Set block to start at the board's entry point
void Chain::Block::initializeLocation(Board &board)
{
	loc = Location(board.getWidth(), board.getScale());
	direction = Location(-1, 0);
}

//if the middle pixel of the next cell in the direction of this block is grey,
//	turn block 90 degrees CCW
//move this block by adding direction onto it
void Chain::moveBlock(Block * block)
{
	const Color WALLCOLOR = Colors::Gray;
	if ((brd.getGfx().getPixel(getMidPoint(block) + (block->direction * brd.scale))) == WALLCOLOR) {
		if (block->direction.X() == 0) {
			block->direction.setX(block->direction.Y());
			block->direction.setY(0);
		}
		else if (block->direction.X() == -1) {
			block->direction.setX(0);
			block->direction.setY(1);
		}
		else {
			block->direction.setX(0);
			block->direction.setY(-1);
		}
	}
	Location offset;
	offset.setX(block->direction.X() * brd.scale);
	offset.setY(block->direction.Y() * brd.scale);
	block->loc = block->loc + offset;
}

//Returns mid-point location of block, rather than the actual location (top-left corner)
Location Chain::getMidPoint(Block * block) const
{
	Location output(int(block->loc.X() + float((0.5 * brd.scale))), int(block->loc.Y() + float((0.5 * brd.scale))));
	return output;
}

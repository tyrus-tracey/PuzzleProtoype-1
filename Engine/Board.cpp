#include "Board.h"
#include "Chain.h"
#include <assert.h>

//Set graphics object and board dimensions
Board::Board(Graphics & gfx)
	:
	gfx(gfx), width(gfx.ScreenWidth), height(gfx.ScreenHeight)
{
}

Board::~Board()
{
}

//Grab width
int Board::getWidth() const
{ return width; }

//Grab height
int Board::getHeight() const
{ return height; }

//Grab scale
int Board::getScale() const
{ return scale; }

Graphics & Board::getGfx() const
{
	return gfx;
}

//Clamp location object within screen boundaries
void Board::Clamp(Location &loc)
{
	if		(loc.X() > width)	{ loc.setX(width); } 
	else if (loc.X() < 0)		{ loc.setX(0); }

	if		(loc.Y() > height)	{ loc.setY(height); } 
	else if	(loc.Y() < 0)		{ loc.setY(0); }
	return;
}

void Board::Clamp(int &x, int &y)
{
	if (x > width - scale) { x = width - scale; }
	else if (x < 0) { x = 0; }

	if (y > height - scale) { y = height - scale; }
	else if (y < 0) { y = 0; }
	return;
}

//Draw a cell based on board's scale
void Board::drawCell(Location &loc, Color c)
{
	gfx.DrawRect(loc.X(), loc.Y(), loc.X() + scale, loc.Y() + scale, c);
}

void Board::drawCell(int x, int y, Color c)
{
	gfx.DrawRect(x, y, x + scale, y + scale, c);
}

void Board::drawVerticalLine(int x, int y0, int y1, Color c)
{
	if (y0 > y1) {
		std::swap(y0, y1);
	}
	for (int i = y0; i < y1; i++) {
		drawCell(x, i, c);
	}
}

void Board::drawHorizontalLine(int x0, int x1, int y, Color c)
{
	if (x0 > x1) {
		std::swap(x0, x1);
	}
	for (int i = x0; i < x1; i++) {
		drawCell(i, y, c);
	}
}

//Create game map
void Board::drawMap()
{
	//Side Borders
	for (int i = 0; i < height - scale; i++) {
		drawCell(0, i, Colors::Gray);
		drawCell(width - scale, i, Colors::Gray);
	}
	//Top-bottom Borders
	for (int j = 0; j < width - scale; j++) {
		drawCell(j, 0, Colors::Gray);
		drawCell(j, height - scale, Colors::Gray);
	}
	//Spiral Map
	//Obtuse way of drawing all the lines necessary for a spiral
	//First draws the top line from left to right (i to width - i) at height i
	//Second draws bottom line from left to right (i to width - scale - i) at (height - scale) - i
	//Third draws left line at column i from i to height - scale - i
	int multiple = 2;
	int loop = scale * 2;
	for (int i = loop; i < (width / 2); i+=loop) {
		drawHorizontalLine(i, (width + 1) - i, i, Colors::Gray);
		drawHorizontalLine(i, (width - scale) - i, (height - scale) - i, Colors::Gray);
		drawVerticalLine(i, i, (height - scale) - i, Colors::Gray);
		drawVerticalLine((width - scale) - i, i + loop, (height - scale) - i, Colors::Gray);
		/* CORNER MARKERS FOR EASY MARKINGS OF LOOPS
		drawCell(i, i, Colors::Red);
		drawCell((width - scale) - i, i, Colors::Red);
		drawCell(i, (height - scale) - i, Colors::Red);
		drawCell((width - scale) - i, (height - scale) - i, Colors::Red);
		*/
		multiple++;
	}
	//Draw a hole
	drawCell(width - scale, scale, Colors::Black);
}

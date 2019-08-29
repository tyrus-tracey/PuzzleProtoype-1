#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Block;
class Board
{
public:
	Board(Graphics & gfx);
	~Board();
	void initialize();
	int getWidth() const;
	int getHeight() const;
	int getScale() const;
	Graphics& getGfx() const;
private:
	friend class Block;
	void Clamp(Location &loc);
	void Clamp(int &x, int &y);
	void drawCell(Location &loc, Color c);
	void drawCell(int x, int y, Color c);
	void drawVerticalLine(int x, int y0, int y1, Color c);
	void drawHorizontalLine(int x0, int x1, int y, Color c);
	void drawMap();
	int width;
	int height;
	const int scale = 40;
	Graphics & gfx;
};


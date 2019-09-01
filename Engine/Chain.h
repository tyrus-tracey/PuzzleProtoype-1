#pragma once
#include "Board.h"

class Chain
{
private:
	class Block
	{
	public:
		Block(Board &board);
		~Block();
		Color getColor() const;
		void draw() const;
		void operator++();
		Location operator*() const;
	private:
		Board & B_brd;
		Color c;
		Location loc;
		Location direction;
	};
public:
	Chain(Board &board);
	~Chain();
private:
	Board &brd;
};


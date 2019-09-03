#pragma once
#include "Board.h"

class Chain
{
private:
	class Block
	{
	public:
		Color getColor() const;
	private:
		friend class Chain;
		void initialize(Board &board);
		void initializeColor();
		void initializeLocation(Board &board);
		Color c;
		Location loc;
		Location direction;
		Block * next = NULL;
		Block * prev = NULL;
	};
public:
	Chain(Board &board);
	~Chain();
	void drawChain();
	void moveChain();
	void growChain();
	void unlinkChain(Block * blockA, Block * blockB);
	bool overThreshold() const;
	Location getMidPoint(Block * block) const;
private:
	void drawBlock(Block *block) const;
	void moveBlock(Block *block);
	Board &brd;
	Block * blocks;
	Block * HEAD;
	Block * TAIL;
	int size;
};


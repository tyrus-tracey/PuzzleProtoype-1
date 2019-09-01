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
		Color c;
		Location loc;
		Location direction;
		void initialize(Board &board);
		void initializeColor();
		void initializeLocation(Board &board);
	};
public:
	Chain(Board &board);
	~Chain();
	void drawBlock(Block &block);
	void moveBlock(Block &block);
	Location getMidPoint(Block &block) const;
private:
	Board &brd;
	Block blocks[100];
	int size;
};


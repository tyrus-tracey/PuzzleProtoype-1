#pragma once

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
		Board &brd;
		Color c;
		Location loc;
		Location direction;
	};
public:
	Chain();
	~Chain();
private:
	Block chain[256];
};


#pragma once
class Location
{
public:
	Location();
	Location(int x, int y);
	Location(Location &loc);
	int X() const;
	int Y() const;
	void setX(const int newValue);
	void setY(const int newValue);
	Location operator+(const Location &loc) const;
	Location operator-(const Location &loc) const;
private:
	int xValue;
	int yValue;
};


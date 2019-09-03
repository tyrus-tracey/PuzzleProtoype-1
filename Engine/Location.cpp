#include "Location.h"

//Default locaction constructor
Location::Location()
	:
	xValue(0), yValue(0)
{
}
//Create a location object with inputted X,Y coordinates
Location::Location(int x, int y)
{
	xValue = x, yValue = y;
}

//Deep copy inputted location's coordinates to current Location object
Location::Location(Location & loc)
{
	xValue = loc.X();
	yValue = loc.Y();
}

//Grab X coordinate
int Location::X() const
{
	return xValue;
}

//Grab Y coordinate
int Location::Y() const
{
	return yValue;
}

//Set new X coordinate
void Location::setX(const int newValue)
{
	xValue = newValue;
}

//Set new Y coordinate
void Location::setY(const int newValue)
{
	yValue = newValue;
}

Location Location::operator+(const Location & loc) const
{
	Location output(xValue + loc.X(), yValue + loc.Y());
	return output;
}

Location Location::operator-(const Location & loc) const
{
	Location output(xValue - loc.X(), yValue - loc.Y());
	return output;
}

Location Location::operator*(const int & factor) const
{
	Location output(X() * factor, Y() * factor);
	return output;
}

Location Location::operator*(const float & factor) const
{
	Location output(int(X() * factor), int(Y() * factor));
	return output;
}

bool Location::operator==(const Location & loc) const
{
	if (xValue == loc.X() && yValue == loc.Y()) {
		return true;
	}
	return false;
}

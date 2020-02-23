// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : LineType.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Implementation of class LineType
//                 See LineType.h for class description
//
// Last Modified : 25 October 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "LineType.h"

LineType::LineType(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void LineType::setCoefficient(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void LineType::displayLine()
{
	cout << fixed << setprecision(2);

	cout << right << setw(5) << a << " x ";

	if (b < 0)
		cout << right << " - " << setw(5) << b * -1 << " y = ";
	else
		cout << right << " + " << setw(5) << b << " y = ";

	cout << right << setw(5) << c << endl;
}

void LineType::lineSlope()
{
	if (a == 0)
		cout << "slope = 0.00" << endl;
	else if (b == 0)
		cout << "slope = infinity" << endl;
	else
		cout << fixed << setprecision(2) << "slope = " << -1 * a * b << endl;
}

bool LineType::operator==(LineType line)
{
	return ((a / line.a) == (b / line.b)  &&  (b / line.b) == (c / line.c));
}

bool LineType::operator||(LineType line)
{
	return (a == 0 && line.a == 0) || (b == 0 && line.b == 0) || (a / b  ==  line.a / line.b);
}

bool LineType::operator&&(LineType line)
{
	return (a == 0 && line.b == 0) || (b == 0 && line.a == 0) || ((a / b) * (line.a / line.b)  ==  -1);
}

void LineType::lineInterestion(LineType line)
{
	float x = (c * line.b  -  b * line.c) / (a * line.b  -  b * line.a);
	float y = (c / b) - ((a / b) * x);

	cout << fixed << setprecision(2) << "Intersect : ( " << x << ", " << y << " )" << endl;
}

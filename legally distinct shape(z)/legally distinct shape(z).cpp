#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

const double PI = 3.14159265358979323846;
class shape {
public:
	shape() {}
	double getArea()
	{
		return 0;
	}
	double getPerimeter()
	{
		return 0;
	}
};

class circle : public shape {
private: 
	double radius;
public:
	circle(double r)
	{
		radius = r;
	}

	double getArea()
	{
		return radius * radius * PI;
	}

	double getPerimeter()
	{
		return 2 * radius * PI;
	}
};

class rectangle : public shape {
private:
	double length;
	double width;
public:
	rectangle(double l, double w)
	{
		length = l;
		width = w;
	}

	double getArea()
	{
		return length * width;
	}

	double getPerimeter()
	{
		return (length + width) * 2;
	}
};

class Rtriangle : public shape {
private:
	double base;
	double height;
public:
	Rtriangle(double l, double w)
	{
		base = l;
		height = w;
	}

	double getArea()
	{
		return base * height * 0.5;
	}

	double getPerimeter()
	{
		return base + height + sqrt((base * base) + (height * height));
	}
};

class square : public rectangle {
public:
	square(double sl) : rectangle(sl, sl) {}
};

class IsoRtriangle : public Rtriangle {
public:
	IsoRtriangle(double sl) : Rtriangle(sl, sl) {}
};

int main()
{
	circle c = circle(1.5);
	rectangle r = rectangle(1.5, 2);
	Rtriangle t = Rtriangle(3, 2);
	square s = square(4);
	IsoRtriangle i = IsoRtriangle(PI);

	cout << "circle A: " << c.getArea() << " P: " << c.getPerimeter() << endl;
	assert(r.getArea() == 3);
	assert(r.getPerimeter() == 7);
	cout << "rect A: " << r.getArea() << " P: " << r.getPerimeter() << endl;
	assert(t.getArea() == 3);
	cout << "tri A: " << t.getArea() << " P: " << t.getPerimeter() << endl;
	assert(s.getArea() == 16);
	assert(s.getPerimeter() == 16);
	cout << "square A: " << s.getArea() << " P: " << s.getPerimeter() << endl;
	cout << "iso tri A: " << i.getArea() << " P: " << i.getPerimeter() << endl;
}
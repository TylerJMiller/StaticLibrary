#include "MyMaths.h"
#include <math.h>

//VECTOR2D
float Vector2::Length()
{
	if (x == 0 && y == 0)
		return 0;
	return sqrt((x * x) + (y * y));
}
float Vector2::Magnitude()
{
	return (x * x) + (y * y);
}
float Vector2::Normal()
{
	if (Length() == 0)
		return 0;

	return sqrt((x / Length())*(x / Length())) + ((y / Length())*(y / Length()));
}
//CONSTRUCTOR
Vector2::Vector2()
{
	x = -1;
	y = -1;
}
Vector2::Vector2(float ax, float ay)
{
	x = ax;
	y = ay;
}

//VECTOR3D
float Vector3::Length()
{
	if (x == 0 && y == 0)
		return z;
	float xy = sqrt((x * x) + (y * y));
	return sqrt((xy * xy) + (z * z));
}
float Vector3::Magnitude()
{
	return (x * x) + (y * y);
}
float Vector3::Normal()
{
	if (Length() == 0)
		return 0;

	return sqrt((x / Length())*(x / Length())) + ((y / Length())*(y / Length()));
}

//CONSTRUCTOR
Vector3::Vector3()
{
	x = -1;
	y = -1;
	z = -1;
}
Vector3::Vector3(float ax, float ay, float az)
{
	x = ax;
	y = ay;
	z = az;
}

//VECTOR4D
Vector4::Vector4()
{
	w = -1;
	x = -1;
	y = -1;
	z = -1;
}
Vector4::Vector4(float aw, float ax, float ay, float az)
{
	w = aw;
	x = ax;
	y = ay;
	z = az;
}

float Vector4::Length()
{
	return sqrt((w * w) + (x * x) + (y * y) + (z * z));
}

void Vector4::Normalize()
{
	w = w / Length();
	x = x / Length();
	y = y / Length();
	z = z / Length();
}


//POINT

//CONSTRUCTOR
Point2::Point2()
{
}
Point2::Point2(float ax, float ay)
{
	x = ax;
	y = ay;
}

//CIRCLE
Circle::Circle()
{
}
Circle::Circle(float XPOS, float YPOS, float RADIUS)
{
	x = XPOS;
	y = YPOS;
	r = RADIUS;
}

//LINE
float Line::Length()
{
	return (((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)));
}
float Line::LengthX()
{
	return (X2 - X1);
}
float Line::LengthY()
{
	return (Y2 - Y1);
}

Vector2 Line::GetVector()
{
	return Vector2(LengthX(), LengthY());
}
Point2 Line::Start()
{
	return Point2(X1, Y1);
}
Point2 Line::End()
{
	return Point2(X2, Y2);
}
//CONSTRUCTOR
Line::Line(Point2 a_point1, Point2 a_point2)
{
	X1 = a_point1.x;
	Y1 = a_point1.y;
	X2 = a_point2.x;
	Y2 = a_point2.y;
}

//BOX
Point2 Box::GetLeftBot()
{
	return Point2(X1, Y1);
}
Point2 Box::GetLeftTop()
{
	return Point2(X1, Y2);
}
Point2 Box::GetRightBot()
{
	return Point2(X2, Y1);
}
Point2 Box::GetRightTop()
{
	return Point2(X2, Y2);
}
Line Box::GetBotLine()
{
	return Line(GetLeftBot(), GetRightBot());
}
Line Box::GetRightLine()
{
	return Line(GetRightBot(), GetRightTop());
}
Line Box::GetTopLine()
{
	return Line(GetRightTop(), GetLeftTop());
}
Line Box::GetLeftLine()
{
	return Line(GetLeftTop(), GetLeftBot());
}

//CONSTRUCTORS
Box::Box()
{
}
Box::Box(Point2 p1, Point2 p2)
{
	X1 = p1.x;
	Y1 = p1.y;
	X2 = p2.x;
	Y2 = p2.y;
}

Box::Box(float ax1, float ay1, float ax2, float ay2)
{
	X1 = ax1;
	Y1 = ay1;
	X2 = ax2;
	Y2 = ay2;
}

//DOT PRODUCT OF TWO VECTORS
float Dot(Vector2 a, Vector2 b)		
{
	return ((a.x * b.x) + (a.y * b.y));
}

//POINT-BOX COLLISION
bool CheckPointBox(Point2 p, Box b)		
{
	if (p.x > b.GetLeftBot().x && p.x < b.GetRightTop().x && p.y > b.GetLeftBot().y && p.y < b.GetRightTop().y)
		return true;
	return false;
}

//COLLISION BETWEEN TWO CIRCLES
bool CheckCircleCircle(Circle a, Circle b)	
{
	return (a.r + b.r) > Distance(a.x, a.y, b.x, b.y);
}

//COLLISION BETWEEN TWO CIRCLES
bool CheckCircleCircle(float ax, float ay, float ar, float bx, float by, float br)	
{
	return (ar + br) > Distance(ax, ay, bx, by);
}

//RETURNS FALSE UNTIL FINISHED
bool CheckLineLine(Line l1, Line l2)
{
	return false;
}

//IF A GIVEN NUMBER IS BETWEEN TWO GIVEN NUMBERS
bool IsWithin(float anum, float amin, float amax)		
{
	if (anum >= amin && anum <= amax)
		return true;
	return false;
}

//BOX-BOX COLLISION - AABB ONE WAY
bool CheckBoxBox(Box b1, Box b2)		
{
	if (CheckPointBox(b1.GetLeftBot(), b2) || CheckPointBox(b1.GetRightBot(), b2) || CheckPointBox(b1.GetRightTop(), b2) || CheckPointBox(b1.GetLeftTop(), b2))
		return true;
	return false;
}

//DISTANCE BETWEEN TWO POINTS
float Distance(Point2 a, Point2 b)		
{
	if (((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)) == 0)
		return 0;
	return (((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
}


//DO NOT DIVIDE BY INFINITE
float Distance(float ax, float ay, float bx, float by)
{
	if (((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)) == 0)
		return 0;
	return sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)));
}

bool CheckPointCircle(Point2 p, Circle c)
{
	if (Distance(p.x, p.y, c.x, c.y) < c.r)
		return true;
	return false;
}

bool CheckPointCircle(float px, float py, float cx, float cy, float cr)
{
	if (Distance(px, py, cx, cy) <= cr)
		return true;
	return false;
}

bool CheckLineCircle(Circle c, Line l)
{
	if (CheckPointCircle(l.Start(), c))
		return true;
	if (CheckPointCircle(l.End(), c))
		return true;

	Vector2 v1(l.X2 - l.X1, l.Y2 - l.Y1);
	Vector2 v2(c.x - l.X1, c.y - l.Y1);
	Vector2 v3((Dot(v2, v1) / v1.Magnitude()) * v1.x, (Dot(v2, v1) / v1.Magnitude()) * v1.y);

	if (v3.Length() > v1.Length())
		return false;
	 
	if (CheckPointCircle(v3.x, v3.y, v2.x, v2.y, c.r))
		return true;

	return false;
}

void Rotate2D(Point2 origin, float radians, Vector2 &v)
{

}
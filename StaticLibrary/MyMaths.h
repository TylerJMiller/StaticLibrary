#ifndef MYMATHS_H
#define MYMATHS_H
class Vector2		//VECTOR CLASS
{
public:
	float x;
	float y;
	//DECLARING DEFAULTS AND OVERLOADS
	Vector2();
	Vector2(float, float);
	void Set(float ax, float ay);

	//OVERLOADS
	void operator=(Vector2 &a);

	//GETTING VALUES
	float Length();
	float Normal();
	float Magnitude();
};

class Vector3		//VECTOR CLASS
{
public:
	float x;
	float y;
	float z;
	//DECLARING DEFAULTS AND OVERLOADS
	Vector3();
	Vector3(float, float, float);
	void Set(float ax, float ay, float az);

	//OVERLOADS
	void operator=(Vector3 &a);

	//GETTING VALUES
	float Length();
	float Normal();
	float Magnitude();
};

class Vector4
{
public:
	float w;
	float x;
	float y;
	float z;
	Vector4();
	Vector4(float, float, float, float);
	float Length();
	void Normalize();
};

class Point2		//POINT CLASS
{
public:
	float x;
	float y;
	//CONSTRUCTORS
	Point2();
	Point2(float, float);
	//SETTING VALUES
	void Set(float ax, float ay);
};

class Circle	//CIRCLE CLASS
{
public:
	float x;
	float y;
	float r;
	Circle();
	Circle(float XPOS, float YPOS, float RADIUS);
	void Set(float XPOS, float YPOS, float RADIUS);
};

class Line		//LINE CLASS
{
public:
	float X1;
	float Y1;
	float X2;
	float Y2;
	//CONSTRUCTORS
	Line();
	Line(Point2, Point2);
	//SETTING VALUES
	void Set(float startx, float starty, float endx, float endy);
	void Set(Point2 a_point1, Point2 a_point2); //SET OVERLOAD USING POINT CLASS
	//GETTING VALUES
	float Length();
	float LengthX();
	float LengthY();
	Point2 Start();
	Point2 End();
	Vector2 GetVector();//GETTING LINE AS VECTOR (FOR SOME REASON)
};

class Box		//BOX CLASS
{
private:
	float X1, Y1, X2, Y2;
public:
	//CONSTRUCTORS
	Box();
	Box(Point2, Point2);
	Box(float, float, float, float);
	//SETTING VALUES
	void Set(float ax, float ay, float ax2, float ay2);
	void Set(Point2 p1, Point2 p2); //SET OVERLOAD USING POINTS
	//GETTING VALUES
	Point2 GetLeftBot();
	Point2 GetLeftTop();
	Point2 GetRightBot();
	Point2 GetRightTop();
	Line GetBotLine();
	Line GetRightLine();
	Line GetTopLine();
	Line GetLeftLine();
};



float Dot(Vector2 a, Vector2 b);		//DOT PRODUCT OF TWO VECTORS

bool CheckPointBox(Point2 p, Box b);		//POINT-BOX COLLISION

bool CheckCircleCircle(Circle a, Circle b);		//CIRCLE-CIRCLE COLLISION

bool CheckCircleCircle(float ax, float ay, float ar, float bx, float by, float br);		//CIRCLE-CIRCLE OVERLOAD

bool CheckLineLine(Line l1, Line l2);				//NOT DONE YET BECAUSE NOT DONE YET

bool IsWithin(float anum, float amin, float amax);		//IF GIVEN NUMBER IS WITHIN GIVEN RANGE

bool CheckBoxBox(Box b1, Box b2);		//BOX-BOX COLLISION - ONLY CHECKS POINTS NOT LINES

float Distance(Point2 a, Point2 b);	//DISTANCE BETWEEN TWO POINTS

float Distance(float ax, float ay, float bx, float by);		//DISTANCE OVERLOAD

bool CheckPointCircle(Point2 p, Circle c);

bool CheckPointCircle(float px, float py, float cx, float cy, float cr);

bool CheckLineCircle(Circle a, Line seg);

bool CheckLineCircle(float ax, float ay, float ar, float lx, float ly);






#endif
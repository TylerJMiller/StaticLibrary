#ifndef RETROREDUX_H
#define RETROREDUX_H

class Vector2		//VECTOR CLASS
{
public:
	float x;
	float y;
	//DECLARING DEFAULTS AND OVERLOADS
	Vector2();
	Vector2(float, float);
	~Vector2();
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
	~Vector3();
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
	~Vector4();
	float Length();
	void Normalize();
};

float RadianToDegree();
float DegreeToRadian();

#endif
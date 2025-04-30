#include "v3.h"
#include <math.h>

V3d::V3d() : x{0.f}, y{ 0.f }, z{ 0.f }
{
}
V3d::V3d(float x, float y, float z) : x{ x }, y{ y }, z{ z }
{
}
V3d V3d::operator+(float value)
{
	return V3d(x + value, y + value, z + value);
}
V3d V3d::operator-(float value)
{
	return V3d(x - value, y - value, z - value);
}
V3d V3d::operator*(float value)
{
	return V3d(x * value, y * value, z * value);
}
V3d V3d::operator/(float value)
{
	return V3d(x / value, y / value, z / value);
}
V3d& V3d::operator+=(float value)
{
	x += value;
	y += value;
	z += value;
	return *this;
}
V3d& V3d::operator-=(float value)
{
	x -= value;
	y -= value;
	z -= value;
	return *this;
}
V3d& V3d::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}
V3d& V3d::operator/=(float value)
{
	x /= value;
	y /= value;
	z /= value;
	return *this;
}
V3d V3d::operator+(const V3d& v)
{

	return V3d(x + v.x, y + v.y, z + v.z);
}
V3d V3d::operator-(const V3d& v)
{
	return V3d(x - v.x, y - v.y, z - v.z);
}
V3d V3d::operator*(const V3d& v)
{
	return V3d(x * v.x, y * v.y, z * v.z);
}
V3d V3d::operator/(const V3d& v)
{
	return V3d(x / v.x, y / v.y, z / v.z);
}
V3d& V3d::operator+=(const V3d& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
V3d& V3d::operator-=(const V3d& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
V3d& V3d::operator*=(const V3d& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
V3d& V3d::operator/=(const V3d& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}
bool V3d::operator==(const V3d& v)
{
	if (x == v.x)
		if (y == v.y)
			if (z == v.z)
				return true;
	return false;
}
V3d V3d::operator!()
{
	return V3d(-1 * x, -1 * y, -1 * z);
}
void V3d::norm()
{
	float length = this->length();
	if (length != 0) 
	{
		x /= length;
		y /= length;
		z /= length;
	}
	else
	{
		x = 1.f;
		y = 1.f;
		z = 1.f;
	}
}
float V3d::length()
{
	return sqrt(x*x + y*y + z*z);
}
void V3d::rotateVector(float alfa, float beta, float gamma)
{
	// os z
	x = x * cos(alfa) - y * sin(alfa);
	y = x * sin(alfa) + y * cos(alfa);
	z = z;
	// os y
	x = x * cos(alfa) + z * sin(alfa);
	y = y;
	z = -x * sin(alfa) + z * cos(alfa);
	// os x
	x = x;
	y = y * cos(alfa) - z * sin(alfa);
	z = y * sin(alfa) + z * cos(alfa);
}
float V3d::angleBetween(const V3d& v1, const V3d& v2, bool a360)
{
	//alfa = arccos((xa*xb + ya*yb + za*zb)/(sqrt(xa^2 + ya^2 + za^2) * sqrt(xb^2 + yb^2 + zb^2))
	//alfa = arccos(licznik / (a * b))
	//alfa = arccos(licznik / mianownik)
	float licznik = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	float a = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	float b = sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z);
	float mianownik = a * b;
	float angle = acos(licznik / mianownik);

	return angle;
}

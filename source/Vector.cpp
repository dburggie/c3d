
#include <c3d.h>
#include <cmath>


/* This file implements the methods of the `Vector` class in the c3p.h header.
 */

namespace c3d 
{
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * CONSTRUCTORS                                                          *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	
	Vector::Vector() { x = 0.0; y = 0.0; z = 0.0; }
	
	Vector::Vector(double x, double y, double z)
	{
		this->x = x; this->y = y; this->z = z;
	}
	
	Vector::Vector(const Vector & v)
	{
		x = v.x; y = v.y; z = v.z;
	}
	
	Vector Vector::clone()
	{
		return Vector(x,y,z);
	}
	
	Vector & Vector::copy(const Vector & v)
	{
		x = v.x; y = v.y; z = v.z;
		return *this;
	}
	
	
	
	
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * GETTERS AND SETTERS                                                   *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	
	Vector & Vector::setxyz(double x, double y, double z)
	{
		this->x = x; this->y = y; this->z = z;
		return *this;
	}
	
	double Vector::getX() { return x; }
	double Vector::getY() { return y; }
	double Vector::getZ() { return z; }
	
	
	
	
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * UNARY METHODS                                                         *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	
	Vector & Vector::normalize()
	{
		double l = length();
		x /= l;
		y /= l;
		z /= l;
		return *this;
	}
	
	double Vector::magnitude()
	{
		return x * x + y * y + z * z;
	}
	
	double Vector::length()
	{
		return std::sqrt(x * x + y * y + z * z);
	}
	
	
	
	
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * BINARY METHODS                                                        *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	
	Vector & Vector::add(const Vector & v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	
	Vector & Vector::subtract(const Vector & v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	
	Vector & Vector::scale(double s)
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	
	double Vector::dot(const Vector & v)
	{
		return x * v.x + y * v.y + z * v.z;
	}
	
	Vector & Vector::cross(const Vector & v)
	{
		double tx, ty, tz;
		tx = y * v.z - z * v.y;
		ty = z * v.x - x * v.z;
		tz = x * v.y - y * v.x;
		x = tx; y = ty; z = tz;
		return *this;
	}
	
	
	
	
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * OTHER TRANSFORMATIONS                                                 *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	
	Vector & Vector::translate(const Vector & v, double s)
	{
		x += s * v.x;
		y += s * v.y;
		z += s * v.z;
		return *this;
	}
	
	
	
	
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * OVERLOADED OPERATORS                                                  *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	
	Vector & Vector::operator=(const Vector & v)
	{
		x = v.x; y = v.y; z = v.z; return *this;
	}
	
	Vector operator+(const Vector & v, const Vector & w) 
	{
		double x, y, z;
		x = v.x + w.x;
		y = v.y + w.y;
		z = v.z + w.z;
		return Vector(x,y,z);
	}
	
	Vector operator-(const Vector & v, const Vector & w)
	{
		double x, y, z;
		x = v.x - w.x;
		y = v.y - w.y;
		z = v.z - w.z;
		return Vector(x,y,z);
	}
	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		os << "{" << v.x << ",";
		os << v.y << ",";
		os << v.z << "}";
		return os;
	}
	
}

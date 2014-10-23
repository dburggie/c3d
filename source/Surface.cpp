#include <c3d.h>
#include <iostream>

namespace c3d
{
	
	
	
	//constructors plus plus
	
	Surface::Surface()
	{
		position.setxyz(0.0,0.0,0.0);
		axisX.setxyz(1.0,0.0,0.0);
		axisY.setxyz(0.0,1.0,0.0);
		axisZ.setxyz(0.0,0.0,1.0);
	}
	
	Surface::Surface(const Vector & pos, const Vector & ox, const Vector & oy)
	{
		position.copy(pos);
		axisX.copy(ox);
		axisY.copy(oy);
		normalize();
	}
	Surface::Surface(const Surface & surface)
	{
		copy(surface);
	}
	
	Surface & Surface::copy(const Surface & surface)
	{
		position.copy(surface.position);
		axisX.copy(surface.axisX);
		axisY.copy(surface.axisY);
		axisZ.copy(surface.axisZ);
		return *this;
	}
	
	
	
	
	
	
	
	//getters / setters
	
	Surface & Surface::setPosition(const Vector & pos)
	{
		position.copy(pos);
		return *this;
	}
	
	Surface & Surface::setAxisX(const Vector & v)
	{
		axisX.copy(v);
		return *this;
	}
	
	Surface & Surface::setAxisY(const Vector & v)
	{
		axisY.copy(v);
		return *this;
	}
	Surface & Surface::setAxisZ(const Vector & v)
	{
		axisZ.copy(v);
		return *this;
	}
	
	Vector & Surface::getPosition()
	{
		return position;
	}
	
	Vector & Surface::getAxisX()
	{
		return axisX;
	}
	
	Vector & Surface::getAxisY()
	{
		return axisY;
	}
	
	Vector & Surface::getAxisZ()
	{
		return axisZ;
	}
	
	
	
	Surface & Surface::copyPositionTo(Vector & v)
	{
		v.copy(position);
		return *this;
	}
	
	Surface & Surface::copyAxisXTo(Vector & v)
	{
		v.copy(axisX);
		return *this;
	}
	
	Surface & Surface::copyAxisYTo(Vector & v)
	{
		v.copy(axisY);
		return *this;
	}
	
	Surface & Surface::copyAxisZTo(Vector & v)
	{
		v.copy(axisZ);
		return *this;
	}
	
	Surface & Surface::normalize()
	{
		axisY.normalize(); //Y is now length one
		axisZ.copy(axisX).cross(axisY).normalize(); //z perpendicular to y and y
		axisX.copy(axisY).cross(axisZ).normalize(); //x perpendicular to x and y
		return *this;
	}
	
	//virtual Surface Surface::clone() is virtual
	//virtual double Surface::intersection(Ray) is virtual
}

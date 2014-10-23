#include <c3d.h>
#include <iostream>

namespace c3d
{
	
	//constructers and more
	Ray::Ray()
	{
		origin = Vector(0.0,0.0,0.0);
		direction = Vector(0.0,1.0,0.0);
	}
	
	Ray::Ray(const Vector & origin, const Vector & direction)
	{
		this->origin = origin;
		this->direction = direction;
	}
	
	Ray::Ray(const Ray & ray)
	{
		origin = ray.origin;
		direction = ray.direction;
	}
	
	Ray Ray::clone()
	{
		return Ray(origin.clone(), direction.clone());
	}
	
	Ray & Ray::copy(const Ray & ray)
	{
		origin.copy(ray.origin);
		direction.copy(ray.direction);
		return *this;
	}
	
	//getters / setters
	Ray & Ray::setOrigin(const Vector & v)
	{
		origin.copy(v);
		return *this;
	}
	
	Ray & Ray::setDirection(const Vector & v)
	{
		direction.copy(v);
		return *this;
	}
	
	Vector & Ray::getOrigin()
	{
		return origin;
	}
	
	Vector & Ray::getDirection()
	{
		return direction;
	}
	
	Vector & Ray::copyOriginTo(Vector & v)
	{
		v.copy(origin);
		return v;
	}
	
	Vector & Ray::copyDirectionTo(Vector & v)
	{
		v.copy(direction);
		return v;
	}
	
	//ray transformations
	Ray & Ray::reflect(const Vector & point, const Vector & normal)
	{
		origin.copy(point);
		double cosine = direction.dot(normal);
		direction.translate(normal, -2.0 * cosine);
		return *this;
	}
	
	Vector Ray::trace(double distance)
	{
		Vector temp = origin.clone();
		temp.translate(direction, distance);
		return temp;
	}
	
	
			//overloaded operators
	Ray & Ray::operator=(const Ray & ray)
	{
		origin.copy(ray.origin);
		direction.copy(ray.direction);
		return *this;
	}
	
	std::ostream & operator<<(std::ostream & os, const Ray & ray)
	{
		return os << "{" << ray.origin << "," << ray.direction << "}";
	}
	
	
}

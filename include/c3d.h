#ifndef C3D_H
#define c3D_H

#include <iostream>

namespace c3d 
{
	
	class Vector 
	{
		
		protected:
			double x, y, z;
		
		public:
			
			//constructors and more
			Vector();
			Vector(double x, double y, double z);
			Vector(const Vector & v);
			Vector clone();
			Vector & copy(const Vector & v);
			
			//setters getters
			Vector & setxyz(double x, double y, double z);
			double getX();
			double getY();
			double getZ();
			
			//vector unary operations
			Vector & normalize();
			double magnitude();
			double length();
			
			//vector binary operations
			Vector & add(const Vector & v);
			Vector & subtract(const Vector & v);
			Vector & scale(double s);
			double dot(const Vector & v);
			Vector & cross(const Vector & v);
			
			//other vector operations
			Vector & translate(const Vector & v, double s);
			
			//overloaded operators
			Vector & operator=(const Vector & v);
			friend Vector operator+(const Vector & v, const Vector & w);
			friend Vector operator-(const Vector & v, const Vector & w);
			friend std::ostream & operator<<(std::ostream & os, const Vector & v);
			
	};
	
	class Ray
	{
		
		protected:
			Vector origin;
			Vector direction;
		
		public:
			
			//constructers and more
			Ray();
			Ray(const Vector & origin, const Vector & direction);
			Ray(const Ray & ray);
			Ray clone();
			Ray & copy(const Ray & ray);
			
			//getters / setters
			Ray & setOrigin(const Vector & v);
			Ray & setDirection(const Vector & v);
			Vector & getOrigin();
			Vector & getDirection();
			Vector & copyOriginTo(Vector & v);
			Vector & copyDirectionTo(Vector & v);
			
			//ray transformations
			Ray & reflect(const Vector & point, const Vector & normal);
			Vector trace(double distance);
			
			//overloaded operators
			Ray & operator=(const Ray & ray);
			friend std::ostream & operator<<(std::ostream & os, const Ray & ray);
		
	};
}

#endif

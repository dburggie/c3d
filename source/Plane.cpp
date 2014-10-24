#include <c3d.h>

namespace c3d
{
	
	class Plane : public Surface
	{
		protected:
			/* Inherited from Surface:
			Vector position;
			Vector axisX;
			Vector axisY;
			Vector axisZ;
			 */
			Vector normal;
		
		public:
			Plane();
			Plane(const Vector & p, const Vector & n);
			Plane(const Plane & p);
			
			//we want to specifically copy over our normal vector
			virtual Plane & copy(const Plane & p);
			
			virtual Plane & setNormal(double x, double y, double z);
			virtual Plane & setNormal(const Vector & v);
			
			//we need to implement our intersection method
			virtual double intersection(Ray & ray);
			
	};
	
	
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * CONSTRUCTORS                                                          *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	
	//default constructor puts us at origin with a 'up' normal vector
	Plane::Plane()
	{
		setPosition(0.0,0.0,0.0);
		setNormal(0.0,1.0,0.0);
	}
	
	Plane::Plane(const Vector & p, const Vector & n)
	{
		setPosition(p);
		setNormal(n);
	}
	
	Plane::Plane(const Plane & p)
	{
		copy(p);
	}
	
	Plane & Plane::copy(const Plane & p)
	{
		setPosition(p.position);
		setAxisX(p.axisX);
		setAxisY(p.axisY);
		setAxisZ(p.axisZ);
		setNormal(p.normal);
		return *this;
	}
	
	Plane & Plane::setNormal(double x, double y, double z)
	{
		normal.setxyz(x,y,z);
		return *this;
	}
	
	Plane & Plane::setNormal(const Vector & n)
	{
		normal.copy(n);
		return *this;
	}
	
	double Plane::intersection(Ray & ray)
	{
		
		double denominator = ray.getDirection().dot(normal);
		if (denominator < 0.000000001) return -1.0;
		
		double distance = position.dot(normal);
		distance -= ray.getOrigin().dot(normal);
		return distance / denominator;
		
	}
	
}


















#ifndef C3D_H
#define c3D_H

#include <iostream>



/* This header file declares the classes implemented in the `c3d` namespace so
 * far. From now on, when we need to declare a class within this namespace,
 * we'll do it here. Then, we'll `include` this file in our implementation
 * source files. In this way, we'll only need to keep track of a single
 * definition for each class and we can reuse this header file both for our
 * implementation source files and later when we want to use the `c3d` module
 * for actual use.
 * 
 * Johnny: Note the frequent use of the keyword `const` in the parameters of the
 * method definitions. This is good practice because it will keep us from
 * accidentally changing the value of the parameter-objects in methods that
 * should not change these values.
 */

namespace c3d 
{
	
	/* The `Vector` class represents either a point in space or a direction
	 * depending on context. Maybe we should add another field that directly
	 * specifies this difference, but abstractly, there isn't actually a
	 * difference mathematically.
	 */
	class Vector 
	{
		
		protected:
			double x, y, z;
		
		public:
			
			//constructors and more
			Vector();
			Vector(double x, double y, double z);
			Vector(const Vector & v); //copy constructor
			Vector clone(); //C++ has less need of this construct than java
			Vector & copy(const Vector & v); //copy the position of v into `this`
			
			//setters / getters -- should be self-explanetory
			Vector & setxyz(double x, double y, double z);
			double getX();
			double getY();
			double getZ();
			
			//vector unary operations
			Vector & normalize(); //scales vector to length one.
			double magnitude(); //returns square of vector length
			double length(); //returns proper vector length
			
			//vector binary operations
			//       note: the methods returning `Vector &` type return `*this`
			Vector & add(const Vector & v); //translate `this` by `v`
			Vector & subtract(const Vector & v); //translate `this` by `-v`
			Vector & scale(double s); //scalar multiplication by `s`
			double dot(const Vector & v); //returns dot product of vectors
			
			/* The method below is strange and we might change it's behavior.
			 * Currently, calling `v.cross(w)` will make the value of `v` equal to its
			 * original value cross the value of `w`. It might be better to return a
			 * new `Vector` object with the value of this cross product.
			 */
			Vector & cross(const Vector & v);
			
			/* The `translate()` method is another strange one, but it's one whose
			 * behavior is actually very useful. When called as `u.translate(v,s)`,
			 * `u`'s value will be translated by the value of `v` scalar-multiplied by
			 * the value of `s`. Note that the value of `v` will be unchanged after 
			 * the method call.
			 */
			Vector & translate(const Vector & v, double s);
			
			//overloaded operators
			Vector & operator=(const Vector & v);
			friend Vector operator+(const Vector & v, const Vector & w);
			friend Vector operator-(const Vector & v, const Vector & w);
			friend std::ostream & operator<<(std::ostream & os, const Vector & v);
			
	};
	
	
	
	/* The `Ray` class is defined two 3-space vectors, both `Vector` objects in
	 * the implementation. These two vectors represent the origin of the ray and
	 * the direction the ray points away from that origin. The direction *should*
	 * always have a magnitude of 1.0, but this isn't necessarily enforced because
	 * you might find it useful to use rays of different "speed".
	 */
	
	class Ray
	{
		
		protected:
			Vector origin;
			Vector direction;
		
		public:
			
			//constructers and more
			Ray();
			Ray(const Vector & origin, const Vector & direction);
			Ray(const Ray & ray); //copy constructor
			Ray clone(); //similar to in the `Vector` class, we may deprecate this
			Ray & copy(const Ray & ray);
			
			//getters / setters
			Ray & setOrigin(const Vector & v);
			Ray & setDirection(const Vector & v);
			Vector & getOrigin();
			Vector & getDirection();
			
			//copy the value of `origin` into a vector `v`
			Vector & copyOriginTo(Vector & v);
			
			//copy the value of `direction` into a vector `v`
			Vector & copyDirectionTo(Vector & v);
			
			//ray transformations
			Ray & reflect(const Vector & point, const Vector & normal);
			Vector trace(double distance);
			
			//overloaded operators
			Ray & operator=(const Ray & ray);
			friend std::ostream & operator<<(std::ostream & os, const Ray & ray);
		
	};
	
	
	/* The Surface class is an abstract class because we have pure virtual
	 * methods. This means we cannot actually make a `Surface` object. Instead, we
	 * will make classes that inherit `Surface` and implement these pure virtual
	 * methods in a manner specific to the particular surface type we're making.
	 * We do things this way because finding the intersection of a ray and a
	 * sphere is very different in practice from finding the intersection of a ray
	 * and a plane, but we still want to treat spheres and planes the same way in
	 * code. We'll accomplish this by accessing the child classes through the
	 * parent `Surface` class interface.
	 */
	
	class Surface
	{
		protected:
			
			
			/* We'll define our generic surface with a single position, and three
			 * orientation vectors.
			 */
			Vector position;
			
			Vector axisX; //direction of 'forward'
			Vector axisY; //direction of 'up'
			Vector axisZ; //direction of 'right'
			
			/* A note on the possibly peculiar directions of the axes above:
			 *   For historical reasons, it's common in video game development to have
			 *   the y-axis be the vertical component. This stems from the days of 2D
			 *   side-scrolling games where y was 'up' (just like with the cartesian
			 *   plane). When the z-axis was added, we did not want to distrupt this
			 *   tradition, so we have the z-axis represent the second horizontal
			 *   component. Of course, you're free to treat whichever axis you want as
			 *   true 'up' when actually using this module. Just be careful to note
			 *   that z must be equal to x cross y.
			 */
		
		public:
			
			//constructors plus plus
			Surface(); //default
			Surface(const Vector & pos, const Vector & ox, const Vector & oy);
			Surface(const Surface & surface); //copy constructor
			//notice I'm not even using a clone method anymore here
			virtual Surface & copy(const Surface & surface);
			
			//getters / setters
			virtual Surface & setPosition(double x, double y, double z);
			virtual Surface & setPosition(const Vector & pos);
			
			virtual Surface & setAxisX(double x, double y, double z);
			virtual Surface & setAxisX(const Vector & v);
			
			virtual Surface & setAxisY(double x, double y, double z);
			virtual Surface & setAxisY(const Vector & v);
			
			virtual Surface & setAxisZ(double x, double y, double z);
			virtual Surface & setAxisZ(const Vector & v);
			
			virtual Vector & getPosition();
			
			virtual Vector & getAxisX();
			virtual Vector & getAxisY();
			virtual Vector & getAxisZ();
			
			virtual Surface & copyPositionTo(Vector & v);
			
			virtual Surface & copyAxisXTo(Vector & v);
			virtual Surface & copyAxisYTo(Vector & v);
			virtual Surface & copyAxisZTo(Vector & v);
			
			virtual Surface & normalize(); // squares xyz axes relative to 'up' (y-axis)
			
			//now for the pure-virtual functions
			virtual double intersection(Ray & ray) = 0; //purely virtual
			
	};
}

#endif

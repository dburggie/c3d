#include <iostream>
#include <c3d.h>

using namespace std;

static int close(double a, double b);



int main(void)
{
	
	c3d::Vector u(1.0,0.0,0.0);
	c3d::Vector v(0.0,1.0,0.0);
	c3d::Vector w(0.0,0.0,1.0);
	
	close(u.dot(v),0.0);
	close(u.dot(w),0.0);
	close(v.dot(w),0.0);
	close(u.add(v).dot(w),0.0);
	close(u.dot(v),1.0);
	cout << u.cross(w) << "\n";
	
	return 0;
	
}



static int close(double a, double b)
{
	static int counter = 0;
	counter++;
	double d = a - b;
	d = (d < 0) ? -d : d;
	if (d < 0.00001) return 1;
	else
	{
		cout << "fail case " << counter << "\n";
		return 0;
	}
}


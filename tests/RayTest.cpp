#include <iostream>
#include <c3d.h>

using namespace std;

static int close(c3d::Ray a, c3d::Ray b);

int main()
{
	c3d::Vector va(1.0,0.0,0.0), vb(0.0,1.0,0.0);//, vc(0.0,0.0,1.0);
	c3d::Ray ra, rb;
	
	ra.setOrigin(va).setDirection(vb);
	rb.setOrigin(va.add(vb)).setDirection(vb);
	ra.getOrigin().add(vb);
	close(ra,rb);
	
	
	cout << ra << ',' << rb << "\n";
	return 0;
}

static int close(c3d::Ray a, c3d::Ray b)
{
	static int counter = 0;
	counter++;
	double od = a.getOrigin().clone().subtract(b.getOrigin()).length();
	double dd = a.getDirection().clone().subtract(b.getDirection()).length();
	
	if (od > 0.000001 || dd > 0.000001)
	{
		cout << "fail case " << counter << "\n";
		return 0;
	}
	
	else return 1;
	
}

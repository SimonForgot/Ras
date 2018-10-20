#include "vec.h"

void vec::get_cross_product_from(vec a, vec b)
{
	this->color = 0x000000;
	//y1z2 - z1y2 , z1x2 - x1z2 , x1y2 - y1x2 )
	arr[0] = a.get(1)*b.get(2)-a.get(2)*b.get(1);
	arr[1] = a.get(2)*b.get(0)-a.get(0)*b.get(2);
	arr[2] = a.get(0)*b.get(1)-a.get(1)*b.get(0);
	arr[3] = 0;
}
class mtx;
void vec::mv_dot(mtx m, vec v)
{
	color = v.color;
	arr[0] = m.getvec(0).dot(v);
	arr[1] = m.getvec(1).dot(v);
	arr[2] = m.getvec(2).dot(v);
	arr[3] = m.getvec(3).dot(v);
}

vec::~vec()
{
}

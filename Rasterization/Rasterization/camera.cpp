#include "camera.h"
camera::~camera()
{
}

void camera::set_view_volume(float _l, float _r, float _t, float _b, float _n, float _f)
{
	l = _l; r = _r; t = _t; b = _b; n = _n; f = _f;
}

void camera::set_axis(vec right, vec up, vec pos)
{
	vec _w;
	_w.get_cross_product_from(right, up);
	w = _w;
	u = right;
	v = up;
	e = pos;

}

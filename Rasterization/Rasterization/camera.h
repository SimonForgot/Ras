#pragma once
#include"vec.h"
class camera
{
private:
	float t,b,l,r,n,f;
	vec u, v, w, e;
public:
	float gett() { return t; }
	float getb() { return b; }
	float getl() { return l; }
	float getr() { return r; }
	float getn() { return n; }
	float getf() { return f; }
	vec getu() { return u; }
	vec getv() { return v; }
	vec getw() { return w; }
	vec gete() { return e; }
	camera()
	{
		set_view_volume(-10, 10, -10, 10, -10, -20);
	}
	camera(vec _u, vec _v)
	{
		u = _u;
		v = _v;
	}
	~camera();
	void set_view_volume(float, float, float, float, float, float);//设置视域参数
	void set_axis(vec,vec,vec);// 根据右手坐标系生成Z轴并设置相机三轴和位置

};

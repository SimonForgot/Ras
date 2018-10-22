#pragma once
#include<array>
#include"vec.h"

class triangle
{
private:
	std::array<vec, 3> t;
	//vec t0, t1, t2;
	friend class pipeline;
public:
	triangle(vec _t0, vec _t1, vec _t2)
	{
		t[0] = _t0;
		t[1] = _t1;
		t[2] = _t2;
	};
	~triangle();
};


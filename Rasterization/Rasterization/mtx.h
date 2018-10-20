#pragma once

#include<array>
#include"vec.h"
class mtx
{
private:
	std::array<vec, 4> m;//4 row vectors
	friend class pipeline;
public:
	mtx() :mtx(vec(0x000000,1,0,0,0),
		vec(0x000000, 0, 1, 0, 0),vec(0x000000, 0, 0, 1, 0),vec(0x000000, 0, 0, 0, 1)) {};
	vec getvec(unsigned);
	mtx(vec v1 , vec v2 , vec v3 , vec v4 )
	{
		m.at(0) = v1;
		m.at(1) = v2;
		m.at(2) = v3;
		m.at(3) = v4;
	}
	void mm_dot(mtx, mtx);
	~mtx();
	
};


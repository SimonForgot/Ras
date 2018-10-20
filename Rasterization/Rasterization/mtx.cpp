#include "mtx.h"

vec mtx::getvec(unsigned i)
{
	return m[i];
}


void mtx::mm_dot(mtx lm, mtx rm)
{
	for (decltype(m.size())i = 0; i < m.size(); i++)
	{
		for (decltype(m[i].arr.size())j = 0; i < m[i].arr.size();j++)
		{

			m[i].arr[j] = lm.m[i].dot(vec(0x000000,rm.m[0].arr[j],
				 rm.m[1].arr[j], rm.m[2].arr[j],rm.m[3].arr[j]));
		}
	}
}

mtx::~mtx()
{
}

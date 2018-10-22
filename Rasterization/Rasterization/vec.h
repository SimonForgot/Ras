#pragma once
#include<array>

class mtx;
class vec
{
private:
	std::array<float, 4> arr;
	uint32_t color;
	friend class mtx;
public:
	vec() :vec(0x000000, 0, 0, 0) {};
	float get(int ii) const { 
		return arr.at(ii);
	}
	vec(uint32_t _color, float xx, float yy, float zz, float ww = 1)
	{
		color = _color;
		arr.at(0) = xx;
		arr.at(1) = yy;
		arr.at(2) = zz;
		arr.at(3) = ww;
		//std::cout <<std::hex<< color;
	}
	void get_cross_product_from(vec, vec);

	const float dot(const vec &v)const
	{
		double sum = 0;
		for (auto i = 0; i < 4; ++i)
		{
			sum += static_cast<double>(arr.at(i))*static_cast<double>(v.get(i));
		}
		return static_cast<float>(sum);
	}
	void mv_dot(mtx, vec);
	//friend class mtx;
	~vec();
};

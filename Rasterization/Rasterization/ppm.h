#pragma once
#include"point.h"
#include<vector>
#include<array>
#include<string>
#include<fstream>
#include<algorithm>
#include<iostream>
class ppm
{
	unsigned int width, height;
	std::vector<std::vector<std::array<unsigned char,3>>> pic;
public:
	ppm(int w,int h);
	void set_pixel(point);
	void draw_line(point , point);
	void draw_triangle(point, point, point);
	void save(const std::string&);
	~ppm();
};


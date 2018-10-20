#pragma once
class point
{
	
public:
	int x, y;
	unsigned char red, green, blue;
	point(int _x, int _y,unsigned char _red= 0x00, unsigned char _green = 0x00,unsigned char _blue = 0x00) :
		x(_x), y(_y),red(_red),green(_green),blue(_blue){ };
	~point();
};


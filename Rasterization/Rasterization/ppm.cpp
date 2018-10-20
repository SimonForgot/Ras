#include "ppm.h"

//初始化ppm文件信息并申请空间
ppm::ppm(int w, int h)
{
	this->width = w;
	this->height = h;
	pic.resize(height);
	for (auto &i : pic)
	{
		i.resize(width, { 0xff,0xff,0xff });
		i.shrink_to_fit();
	}
	pic.shrink_to_fit();
	//std::cout << pic.size() << " " << pic.at(0).size()<<" "<< pic.at(0).at(0).size();
}
void ppm::set_pixel(point p)
{
	pic[p.y][p.x][0] = p.red;
	pic[p.y][p.x][1] = p.green;
	pic[p.y][p.x][2] = p.blue;
}

//绘制直线
void ppm::draw_line(point p1, point p2)
{
	//test
	if (p1.x > p2.x)std::swap(p1, p2);
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	float k = static_cast<float>(dy) / dx;
	//std::cout << k;
	if (k > 0 && k < 1) {
		int y = p1.y;
		float d = (p1.y - p2.y)*(p1.x + 1) + (p2.x - p1.x)*(p1.y + 0.5) + p1.x*p2.y - p2.x*p1.y;
		for (int x = p1.x; x <= p2.x; ++x)
		{
			//绘制像素点
			set_pixel(point(x, y));
			if (d < 0)
			{
				y++;
				d += (p2.x - p1.x + p1.y - p2.y);
			}
			else {
				d += (p1.y - p2.y);
			}
		}
	}if (k > 0 && k >= 1) {
		int x = p1.x;
		float d = (p1.y - p2.y)*(p1.x + 0.5) + (p2.x - p1.x)*(p1.y + 1) + p1.x*p2.y - p2.x*p1.y;
		for (int y = p1.y; y <= p2.y; ++y)
		{
			//绘制像素点
			set_pixel(point(x, y));
			if (d > 0)
			{
				x++;
				d += (p2.x - p1.x + p1.y - p2.y);
			}
			else {
				d += (p2.x - p1.x);
			}
		}
	}
	if (k < 0 && k <= -1)
	{
		int x = p1.x;
		float d = (p1.y - p2.y)*(p1.x + 0.5) + (p2.x - p1.x)*(p1.y - 1) + p1.x*p2.y - p2.x*p1.y;
		for (int y = p1.y; y >= p2.y; --y)
		{
			//绘制像素点
			set_pixel(point(x, y));
			if (d < 0)
			{
				x++;
				d += (p1.x - p2.x + p1.y - p2.y);
			}
			else {
				d += (p1.x - p2.x);
			}
		}
	}
	if (k < 0 && k > -1)
	{
		int y = p1.y;
		float d = (p1.y - p2.y)*(p1.x + 1) + (p2.x - p1.x)*(p1.y - 0.5) + p1.x*p2.y - p2.x*p1.y;
		for (int x = p1.x; x <= p2.x; ++x)
		{
			//绘制像素点
			set_pixel(point(x, y));
			if (d > 0)
			{
				y--;
				d += (p1.x - p2.x + p1.y - p2.y);
			}
			else {
				d += (p1.y - p2.y);
			}
		}
	}


	//std::cout << p1.x << p1.y << p2.x << p2.y;
}
//draw triangle
void ppm::draw_triangle(point p0, point p1, point p2)
{
	std::array<int, 3>xs{ p0.x, p1.x, p2.x };
	std::array<int, 3>ys{ p0.y, p1.y, p2.y };
	int xmin = *(std::min_element(xs.begin(), xs.end()));
	int xmax = *(std::max_element(xs.begin(), xs.end()));
	int ymin = *(std::min_element(ys.begin(), ys.end()));
	int ymax = *(std::max_element(ys.begin(), ys.end()));
	int fa = (p1.y - p2.y)*p0.x + (p2.x - p1.x)*p0.y + p1.x * p2.y - p2.x * p1.y;
	int fb = (p2.y - p0.y)*p1.x + (p0.x - p2.x)*p1.y + p2.x * p0.y - p0.x * p2.y;
	int fy = (p0.y - p1.y)*p2.x + (p1.x - p0.x)*p2.y + p0.x * p1.y - p1.x * p0.y;
	for (int _y = ymin; _y != ymax; ++_y)
	{
		for (int x = xmin; x != xmax; ++x)
		{
			double a= ((p1.y - p2.y)*x + (p2.x - p1.x)*_y + p1.x * p2.y - p2.x * p1.y)/
				static_cast<double>(fa);
			double b=((p2.y - p0.y)*x + (p0.x - p2.x)*_y + p2.x * p0.y - p0.x * p2.y)/
				static_cast<double>(fb);
			double y=((p0.y - p1.y)*x + (p1.x - p0.x)*_y + p0.x * p1.y - p1.x * p0.y)/
				static_cast<double>(fy);
			if (a >= 0 && b >= 0 && y >= 0)
			{
				if ((a > 0 || fa * ((p2.y - p0.y)*(-1) + (p0.x - p2.x)*(-1) + p2.x * p0.y - p0.x * p2.y) > 0)
					&& (b > 0 || fb * ((p2.y - p0.y)*(-1) + (p0.x - p2.x)*(-1) + p2.x * p0.y - p0.x * p2.y) > 0)
					&& (y > 0 || fy * ((p0.y - p1.y)*(-1) + (p1.x - p0.x)*(-1) + p0.x * p1.y - p1.x * p0.y) > 0))
				{
					set_pixel(point(x, _y, 
						static_cast<unsigned char>(a*p0.red + b * p1.red + y * p2.red),
						static_cast<unsigned char>(a*p0.green + b * p1.green + y * p2.green),
						static_cast<unsigned char>(a*p0.blue + b * p1.blue + y * p2.blue)));
				}
			}
		}
	}
}

void ppm::save(const std::string& filename)
{
	std::reverse(pic.begin(), pic.end());
	std::ofstream of(filename);
	of << "P3\n" << width << " " << height << "\n" << "255\n";
	for (auto &i : pic)
	{
		for (auto &j : i)
		{
			for (auto &k : j)
			{
				of << (unsigned)k << " ";
				//if((int)k!=0)
				//std::cout << (int)k;
			}
		}
		of << '\n';
	}
	of.close();
}

ppm::~ppm()
{
}

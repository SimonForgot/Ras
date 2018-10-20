#pragma once
#include"triangle.h"
#include"camera.h"
#include"mtx.h"
#include"ppm.h"
#include<string>
#include<vector>
class pipeline
{
private:
	unsigned width, height;//Í¼Ïñ¿í¸ß
	std::vector<std::vector<unsigned char>> image_buffer;
	std::vector<triangle>primitive_buffer;
	//std::vector<triangle>primitive_buffer;
	unsigned int num_primitives;
	mtx Mcama, Mcamb, Mcam, Mper, Mvp, M;
	camera cam;
public:
	void put_in(triangle);
	void vertex_processing();//get transformed geometry (screen coordinates)
	void set_camera_view_volume(float l,float r,float t,float b,float n,float f);//set view volume
	void set_camera_axis(vec, vec, vec);
	void set_screen_size(unsigned, unsigned);
	void Rasterization();
	void draw_to_ppm(std::string);
	pipeline();
	~pipeline();
};


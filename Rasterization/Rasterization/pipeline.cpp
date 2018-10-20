#include "pipeline.h"
pipeline::pipeline()
{
	width = 800;
	height = 600;
	primitive_buffer = {};
	num_primitives = 0;
}

void pipeline::put_in(triangle t)
{
	primitive_buffer.push_back(t);
	num_primitives = primitive_buffer.size();
}

void pipeline::vertex_processing()
{
	Mcam.mm_dot(Mcama, Mcamb);
	mtx Mpered;
	Mpered.mm_dot(Mper, Mcam);
	M.mm_dot(Mvp, Mpered);
	for (auto &tri : primitive_buffer)
	{
		for (auto &v : tri.t)
		{
			v.mv_dot(M,v);
		}
	}
}

void pipeline::set_camera_view_volume(float l, float r, float t, float b, float n, float f)
{
	cam.set_view_volume(l, r, t, b, n, f);
	Mper = mtx(
		vec(0x000000,2*cam.getn()/(cam.getr()-cam.getl()),0,(cam.getl()+cam.getr())/(cam.getl()-cam.getr()),0), 
		vec(0x000000, 0,2*cam.getn()/(cam.gett()-cam.getb()), (cam.getb() + cam.gett()) / (cam.getb() - cam.gett()),0),
		vec(0x000000, 0,0, (cam.getf() + cam.getn()) / (cam.getn() - cam.getf()), 2 *cam.getf()* cam.getn() / (cam.getf() - cam.getn())),
		vec(0x000000, 0,0,1,0));
}

void pipeline::set_camera_axis(vec right, vec up, vec pos)
{
	cam.set_axis(right, up, pos);
	Mcama = mtx(cam.getu(), cam.getv(), cam.getw(),vec(0x000000,0,0,0,1));
	Mcamb = mtx(vec(0x000000,1,0,0,-cam.gete().get(0)),
		vec(0x000000, 0, 1, 0, -cam.gete().get(1)),
		vec(0x000000, 0, 0, 1, -cam.gete().get(2)),
		vec());
}

void pipeline::set_screen_size(unsigned w, unsigned h)
{
	width = w;
	height = h;
	//为buffer开辟空间
	image_buffer.resize(height);
	for (auto &i : image_buffer)
	{
		i.resize(width);
	}
	//Mvp矩阵赋值
	Mvp = mtx(vec(0x000000,width/2.0,0,0, (width-1) / 2.0),
		vec(0x000000, 0,height/2.0 ,0 , (height - 1) / 2.0),
		vec(0x000000, 0, 0,1 ,0 ), 
		vec(0x000000,0 , 0, 0,1 ));
}

void pipeline::Rasterization()
{
}

void pipeline::draw_to_ppm(std::string)
{

}



pipeline::~pipeline()
{
}

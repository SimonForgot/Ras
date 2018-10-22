#include"geometry.h"
#include"pipeline.h"
int main()
{
	const unsigned width = 800, height = 600;//screen size
	vec v0(0xff0000,7,8,-12),v1(0x00ff00,-6,4,-18),v2(0x0000ff,1,-8,-10);
	triangle tri(v0, v1, v2);//three verteies of a triangle
	pipeline line;
	line.set_camera_view_volume(-10,10,-10,10,-10,-20);//l r t b n f
	vec position(0x000000,0,0,0);
	vec right_direction(0x000000, 1, 0, 0,0);//normolized vector
	vec up_direction(0x000000, 0, 1, 0,0);//must be orthogonal to right vec
	line.set_camera_axis(right_direction,up_direction,position);
	line.set_screen_size(width, height);
	line.put_in(tri);
	line.vertex_processing();//get transformed geometry (vertex screen coordinates(with z inf))
	line.Rasterization();//use verteies to get fragments and operate on them

	line.draw_to_ppm("triangle.ppm");
	getchar();
	return 0;
}
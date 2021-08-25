#include "Segment.h"

Segment::Segment(float x_, float y_, float len_, float angle_, const olc::Pixel& col)
{
	ax = x_;
	ay = y_;
	len = len_;
	angle = angle_;
	color = col;
}

void Segment::Update()
{
	ComputeB();
	//std::cout << bx << " " << by << " " << angle << std::endl;
}

void Segment::ComputeB()
{
	float dx = len * cos(angle);
	float dy = len * sin(angle);
	bx = ax + dx;
	by = ay + dy;
}

void Segment::DrawSelf(olc::PixelGameEngine* gfx)
{
	//if (std::isnan(bx) || std::isnan(by)) return;
	gfx->DrawLine(ax, ay, bx, by, color);
}
void Segment::follow(float x_, float y_)
{
	angle = atan2(y_, x_);
}
void Segment::follow(float angle_)
{
	angle = angle_;

}
void Segment::setA(float x_, float y_)
{
	ax = x_;
	ay = y_;
}
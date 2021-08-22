#include "Segment.h"



Segment::Segment(float x_, float y_, float len_, float angle_)
{
	ax = x_;
	ay = y_;
	len = len_;
	angle = angle_;
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
	gfx->DrawLine(ax, ay, bx + gfx->ScreenWidth() / 2, by, olc::RED);
}
void Segment::follow(float x_, float y_)
{
	angle = atan2(x_ + ay, x_ + ax);
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

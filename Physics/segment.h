#pragma once
#include "olcPixelGameEngine.h"

class Segment
{
public:
	float len = 0.0f;
	float angle = 0.0f;
	float ax = 0.0f;
	float ay = 0.0f;
	float bx = 0.0f;
	float by = 0.0f;
	
	olc::Pixel color;
	Segment() {}
	Segment(float x, float y, float len_, float angle_, const olc::Pixel& col);

	void Update();
	void ComputeB();
	void DrawSelf(olc::PixelGameEngine* gfx);
	void follow(float x_, float y_);
	void follow(float angle_);
	void setA(float x_, float y_);


private:

};

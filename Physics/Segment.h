#pragma once
#include <iostream>
#include <math.h>

#include "olcPixelGameEngine.h"

class Segment
{
public:
	float len;
	float angle;
	float ax;
	float ay;
	float bx;
	float by;
	Segment(float x, float y, float len_, float angle_);


	void Update();
	void ComputeB();
	void DrawSelf(olc::PixelGameEngine* gfx);
	void follow(float x_, float y_);
	void follow(float angle_);
	void setA(float x_, float y_);


private:
	
};


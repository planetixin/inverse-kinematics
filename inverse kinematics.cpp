#include <iostream>
#include <math.h>
#include "Segment.h"

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


class InverseKinemtics : public olc::PixelGameEngine
{
public:
    InverseKinemtics()
    {
        sAppName = "Inverse Kinematics test";
    }
private:
    float x, y;
    float len1 = 30;
    float len2 = 20;
    Segment* seg1 = new Segment(ScreenWidth()/2, ScreenHeight()/2, len1, 0.0f);
    Segment* seg2 = new Segment(ScreenWidth() / 2, ScreenHeight() / 2, len2, 0.0f);



protected:
    virtual bool OnUserCreate()
    {
        //seg1 = new Segment(0.0f, 0.0f, 50.0f ,0.0f);
        
        return true;
    }
    virtual bool OnUserUpdate(float fElapsedTime)
    {

        for (int x = 0; x < ScreenWidth(); x++)
        {
            for (int y = 0; y < ScreenHeight(); y++)
            {
                Draw(x, y, olc::Pixel(olc::BLUE));
            }
        }
        //float angle = atan2(GetMouseY() - ay - ScreenHeight() / 2, GetMouseX() - ax - ScreenWidth() / 2);
        //float nAngle = angle * (180 / 3.141592653589793238463);
        //float dx = len * cos(angle);
        //float dy = len * sin(angle);
        x = GetMouseX();
        y = GetMouseY();

        float q1;
        float q2 = acos((sqrt(x) + sqrt(y) - sqrt(len1)-sqrt(len2))/(2*len1*len2));
        q1 = atan(y/x)-atan((len1*sin(q2)) / (len1+len2*cos(q2)));

        seg1->follow(x, y);
        seg2->follow(q2+seg1->angle);
        
        
        seg1->Update();
        seg1->DrawSelf(this);
        seg2->Update();
        seg2->DrawSelf(this);
        seg1->setA(seg1->bx, seg2->by);
        
        //DrawLine(seg1->ax + ScreenWidth() / 2, seg1->ax + ScreenHeight() / 2, seg1->bx + ScreenWidth() / 2, seg1->by + ScreenHeight() / 2, olc::RED);
        //DrawLine(seg2->ax + ScreenWidth() / 2, seg2->ax + ScreenHeight() / 2, seg2->bx + ScreenWidth() / 2, seg2->by + ScreenHeight() / 2, olc::RED);

        //DrawLine(ScreenWidth()/2, ScreenHeight() / 2, GetMouseX(), GetMouseY(), olc::WHITE);
        //DrawLine(ax + ScreenWidth() / 2, ay + ScreenHeight() / 2, dx + ScreenWidth() / 2 + ax, dy + ScreenHeight() / 2 + ay, olc::RED);

        return true;
    }

};


int main()
{
    InverseKinemtics demo;
    if (demo.Construct(240, 200, 4, 4))
    {
        demo.Start();
    }
    return 0;
}


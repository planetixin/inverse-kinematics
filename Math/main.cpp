#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#define M_PI 3.14159265358979323846
#include "Segment.h"

class InverseKinematics : public olc::PixelGameEngine
{
public:
    InverseKinematics()
    {
        sAppName = "Inverse Kinematics test";
    }
private:
    float x, y;
    float len1 = 50;
    float len2 = 40;
    float len3 = len1 + len2;
    float pivot_x, pivot_y;

    Segment seg1, seg2, seg3;

    float Clamp(float value, float a, float b) { return value <= a ? a : (value >= b ? b : value); }
protected:
    virtual bool OnUserCreate()
    {
        //seg1 = new Segment(0.0f, 0.0f, 50.0f ,0.0f);
        seg1 = Segment(ScreenWidth() / 2, ScreenHeight() / 2, len1, 0.0f, olc::RED);
        seg2 = Segment(ScreenWidth() / 2, ScreenHeight() / 2, len2, 0.0f, olc::RED);
        seg3 = Segment(ScreenWidth() / 2, ScreenHeight() / 2, len1+len2, 0.0f, olc::WHITE);



        pivot_x = ScreenWidth() / 2.0f; pivot_y = ScreenHeight() / 2.0f;

        return true;
    }
    virtual bool OnUserUpdate(float fElapsedTime)
    {

        Clear(olc::BLUE);
        x = GetMouseX() - ScreenWidth() / 2.0f;
        y = GetMouseY() - ScreenHeight() / 2.0f;
        //x = GetMouseX(); y = GetMouseY();
        float dis = sqrt(pow(x, 2) + pow(y, 2));

        if (len1 - len2 <= dis && dis <= len1 + len2)
        {
            len3 = dis;
            //std::cout << dis;
        }
        else if(dis > len1 + len2)
        {
            len3 = len1 + len2;
        }
        else if (dis < len1 - len2)
        {
            len3 = len1 - len2;
        }
        
        //float m_angle = atan2f(GetMouseY() - seg2.ay, GetMouseX() - seg2.ax);

        float cosAlfa = ((len3 * len3) + (len1 * len1) - (len2 * len2)) / (2 * len3 * len1);
        float alfa = acos(cosAlfa);

        float cosBeta = ((len2*len2)+ (len1 * len1) - (len3 * len3))/(2*len2*len1);
        float beta = acos(cosBeta);


        float B = M_PI + beta;
        float Aquat = atan2((GetMouseY() - seg1.ay) , (GetMouseX() - seg1.ax));
        float A = Aquat + alfa;



        seg1.follow(A);

        seg2.follow(B + A);
        //seg2.angle = m_angle;
        //seg2.ax = GetMouseX() - seg2.len * cosf(seg2.angle);
        //seg2.ay = GetMouseY() - seg2.len * sinf(seg2.angle);
        
        //seg1.angle = atan2f(seg2.ay - seg1.ay, seg2.ax - seg1.ax);
        //seg1.ax = seg2.ax - seg1.len * cosf(seg1.angle);
        //seg1.ay = seg2.ay - seg1.len * sinf(seg1.angle);

        seg3.follow(x,y);
        seg3.len = len3;
        
        //seg1.ax = pivot_x; seg1.ay = pivot_y;
        seg1.Update();
        seg2.ax = seg1.bx;
        seg2.ay = seg1.by;
        seg2.Update();
        seg3.Update();

        if (GetMouse(0).bPressed)
        {
            std::cout << seg1.bx << " " << seg1.by << std::endl;
        }
        //DrawLine(seg1.ax, seg1.ay, seg2.bx, seg2.by, olc::WHITE);

        seg1.DrawSelf(this);
        //seg2.setA(seg1.bx, seg1.by);

        seg2.DrawSelf(this);
        seg3.DrawSelf(this);

        return true;
    }

};

int main()
{
    InverseKinematics demo;
    if (demo.Construct(440, 400, 2, 2, false, true))
    {
        demo.Start();
    }
    return 0;
}

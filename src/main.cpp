#include <iostream>
#include <math.h>

#include "../include/vibes.h"
//using namespace std;


void draw_road(double x, double y, double l);

void draw_robot(double pos, double r);

double f(float x, float v, float u, float& xdot, float& vdot);

int main(int argc, char *argv[])
{
    int l = 100;
    float dt = 0.05;
    int vo = 3;
    int u = 1;
    double r = l / (2 * M_PI);  // defines radius based on desired circunference

    vibes::beginDrawing();
    vibes::newFigure("Road");
    vibes::setFigureProperties("Road",
                               vibesParams("x", 100, "y", 100,
                                          "width", 400, "height", 400)
                              );
    vibes::axisLimits(-20., 20., -20., 20.);

    draw_road(0,0,r);

    draw_robot(20,r);



    vibes::endDrawing();
    return 0;
}

double f(float x, float v, float u, float& xdot, float& vdot)
{
   return 1.0;
}

void draw_robot(double pos, double r)
{
    double th = pos / r;       // theta defined by position on the road
    double px = r * cos(th);   // pos x in the plane
    double py = r * sin(th);   // pos x in the plane
    double pr = th + (M_PI/2);

    vibes::drawTank(px, py, pr, 4, "black[white]", vibesParams("figure", "Road"));
}

void draw_road(double x, double y, double r)
{
    double r1 = r - 2.5;        // two circles will be 2.5 units distant from the middle of the road
    double r2 = r + 2.5;        //  so that to have 5 width

    vibes::clearFigure("Road");
    vibes::drawCircle(x, y, r1);
    vibes::drawCircle(x, y, r2);
}

#include <iostream>
#include <math.h>
#include <unistd.h>
#include "../include/vibes.h"
//using namespace std;

struct State
{
    double x;
    double v;
};

void draw_road(double cx, double cy, double l);

void draw_robot(double pos, double r);

void f(double x, double v, double u, double& xdot, double& vdot);

void euler(double& x, double& v, double xdot, double vdot, double dt);

int main(int argc, char *argv[])
{
    int l, v0, u;
    double dt, r, x, v, xdot, vdot;
    l = 100;
    dt = 0.05;
    v0 = 3;
    r = l / (2 * M_PI);  // defines radius based on desired circunference
    x = v = 0;
    u = xdot = vdot = 1;


    vibes::beginDrawing();
    vibes::newFigure("Road");
    vibes::setFigureProperties("Road",
                               vibesParams("x", 100, "y", 100,
                                          "width", 400, "height", 400)
                              );
    vibes::axisLimits(-20., 20., -20., 20.);



    for (int t = 0; t < 101; t++)
    {
//        std::cout << "t: " << t << std::endl;
        f(x,v,u,xdot,vdot);
        euler(x,v,xdot,vdot,dt);

        draw_road(0,0,r);
        draw_robot(x,r);

        usleep(dt * 500000);
    }

    vibes::endDrawing();
    return 0;
}

void euler(double& x, double& v, double xdot, double vdot, double dt)
{
    double dx = xdot*dt;
    double dv = vdot*dt;
    x = x + dx;  // x = xdot * dt
    v = v + dv;  // v = vdot * dt
}

void f(double x, double v, double u, double& xdot, double& vdot)
{
    xdot = v;
    vdot = u; // according to equation (1)
}

void draw_robot(double x, double r)
{
    double th = x / r;         // theta defined by position on the road
    double px = r * cos(th);   // pos x in the plane
    double py = r * sin(th);   // pos x in the plane
    double pr = th + M_PI/2.;

    vibes::drawTank(px, py, pr, 4, "black[white]", vibesParams("figure", "Road"));
}

void draw_road(double cx, double cy, double r)
{
    double r1 = r - 2.5;        // two circles will be 2.5 units distant from the middle of the road
    double r2 = r + 2.5;        //  so that to have 5 width

    vibes::clearFigure("Road");
    vibes::drawCircle(cx, cy, r1);
    vibes::drawCircle(cx, cy, r2);
}

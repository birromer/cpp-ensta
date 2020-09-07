#include <iostream>
#include <math.h>

#include "../include/vibes.h"
//using namespace std;


void draw_road(double x, double y, double l)
{
    double r = l / (2 * M_PI);
    double r1 = r - 2.5;
    double r2 = r + 2.5;

    vibes::clearFigure("Road");
    vibes::drawCircle(x, y, r1);
    vibes::drawCircle(x, y, r2);
}

int main(int argc, char *argv[])
{
    int l = 100;
    float dt = 0.05;
    int vo = 3;
    int u = 1;

    vibes::beginDrawing();
    vibes::newFigure("Road");
    vibes::setFigureProperties("Road",
                               vibesParams("x", 100, "y", 100,
                                          "width", 400, "height", 400)
                              );
    vibes::axisLimits(-20., 20., -20., 20.);

    draw_road(0,0,5);




    vibes::endDrawing();
    return 0;
}

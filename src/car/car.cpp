#include "../../include/car.h"

Car::Car(int x, double v, const Road *road) : x(x), v(v), road(road){

}



//void Car::draw(double x, double r)
//{
//  double th = x / r;         // theta defined by position on the road
//  double px = r * cos(th);   // pos x in the plane
//  double py = r * sin(th);   // pos x in the plane
//  double pr = th + M_PI/2.;  // heading
//  pr = pr * (180.0/M_PI);    // the exercise says th + pi/2 but it the draw functions seems to work with degrees 
//
//  vibes::drawTank(px, py, pr, 4, "black[white]", vibesParams("figure", "Jam"));
//}
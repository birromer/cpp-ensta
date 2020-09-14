#include "../../include/car.h"

Car::Car(double x, double v, const Road *road) : _x(x), _v(v), road(road) {

}

Car::Car(double x, const Road *road) : _x(x), _v(0.), road(road) {

}

double Car::x() {
  return _x;
}

double Car::v() {
  return _v;
}

void Car::set(int pos, double spe) {
  _x = pos;
  _v = spe;
}

void Car::stop() {
  _v = 0.0;
}

void Car::set_front_car(Car &car) {
  front_car = &car;
}

Car Car::get_front_car() {
  return *front_car;
}

void Car::draw()
{
  double r = road->length();
  double th = x() / r;         // theta defined by position on the road
  double px = r * cos(th);   // pos x in the plane
  double py = r * sin(th);   // pos x in the plane
  double pr = th + M_PI/2.;  // heading
  pr = pr * (180.0/M_PI);    // the exercise says th + pi/2 but it the draw functions seems to work with degrees 

  vibes::drawTank(px, py, pr, 4, "black[white]", vibesParams("figure", "Jam"));
}

void Car::f(double u, double& xdot, double& vdot) const
{
  xdot = _v;
  vdot = u; // according to equation (1)
}
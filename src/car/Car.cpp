#include "../../include/Car.h"
#include <iostream>

Car::Car(double x, double v, const Road *road) : _x(x), _v(v), road(road) {

}

Car::Car(double x, const Road *road) : _x(x), _v(0.), road(road) {

}

double Car::x() const {
  return _x;
}

double Car::v() const {
  return _v;
}

void Car::set(int pos, double spe) {
  _x = pos;
  _v = spe;
}

void Car::stop() {
  _v = 0.0;
}

void Car::set_front_car(Car *car) {
  _front_car = car;
}

const Car* Car::get_front_car() const{
  return _front_car;
}

const Road* Car::get_road() const {
  return road;
}

void Car::draw() const {
  double r = road->radius();
  double th = _x / r;         // theta defined by position on the road
  double px = r * cos(th);   // pos x in the plane
  double py = r * sin(th);   // pos x in the plane
  double pr = th + M_PI/2.;  // heading
  pr = pr * (180.0/M_PI);    // the exercise says th + pi/2 but it the draw functions seems to work with degrees 

  vibes::drawTank(px, py, pr, 4, "black[white]", vibesParams("figure", "Jam"));
}

bool Car::collision() const {
  double cd = road->circular_dist(*get_front_car(), *this);
  return fabs(cd) < 5;
}

void Car::f(double u, double& xdot, double& vdot) const
{
  xdot = _v;
  vdot = u; // according to equation (1)
}

double Car::u(double d0, double v0) const {
  return 1;
}

void Car::euler(double xdot, double vdot, double dt) {
  double dx = xdot*dt;
  double dv = vdot*dt;
  _x = _x + dx;  // x = xdot * dt
  _v = _v + dv;  // v = vdot * dt
}
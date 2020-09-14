#include "../../include/car.h"

Car::Car(int x, double v, const Road *road) : x(x), v(v), road(road) {

}

Car::Car(int x, const Road *road) : x(x), v(0.), road(road) {

}

int Car::get_x() {
  return x;
}

double Car::get_v() {
  return v;
}

void Car::set(int pos, double spe) {
  x = pos;
  v = spe;
}

void Car::stop() {
  v = 0.0;
}


void Car::set_front_car(Car &car) {
  front_car = &car;
}

Car Car::get_front_car() {
  return *front_car;
}

void Car::draw()
{
  Road rd = *road;
  const double r = rd.length();
  double th = x / r;         // theta defined by position on the road
  double px = r * cos(th);   // pos x in the plane
  double py = r * sin(th);   // pos x in the plane
  double pr = th + M_PI/2.;  // heading
  pr = pr * (180.0/M_PI);    // the exercise says th + pi/2 but it the draw functions seems to work with degrees 

  vibes::drawTank(px, py, pr, 4, "black[white]", vibesParams("figure", "Jam"));
}
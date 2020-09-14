#ifndef __CAR_H__
#define __CAR_H__

#include <math.h>
#include "../include/road.h"

class Road;

class Car {
  public:
    Car(double x, double v, const Road *road);
    Car(double x, const Road *road);
    double x();
    double v();
    void set(int x, double v);
    void draw();
    void stop();
    void set_front_car(Car &car);
    Car get_front_car();
    void f(double u, double& xdot, double& vdot) const;

  private:
    double _x;
    double _v = 0;
    const Road *road;
    const Car *front_car;
};

#endif
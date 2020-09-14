#ifndef __CAR_H__
#define __CAR_H__

#include <math.h>
#include "../include/Road.h"

class Road;

class Car {
  public:
    Car(double x, double v, const Road *road);
    Car(double x, const Road *road);

    double x() const;
    double v() const;

    void set(int x, double v);
    void stop();

    void draw() const;

    void set_front_car(Car *car); // defines the front car
    const Car* get_front_car() const; // gets a *pointer* to the car in the front
    const Road* get_road() const; // gets a *pointer* to the road

    bool collision() const; // tests if circular distance smaller than 4 (size of the car)

    void f(double u, double& xdot, double& vdot) const;
    double u(double d0, double v0) const;
    void euler(double xdot, double vdot, double dt);

  private:
    double _x;
    double _v = 0;
    const Road *road;
    const Car *_front_car;
};

#endif
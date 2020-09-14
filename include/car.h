#ifndef __CAR_H__
#define __CAR_H__

#include <math.h>
#include "../include/road.h"

class Road;

class Car {
  public:
    Car(int x, double v, const Road *road);
    Car(int x, const Road *road);
    int get_x();
    double get_v();
    void set(int x, double v);
    void draw();
    void stop();
    void set_front_car(Car &car);
    Car get_front_car();

  private:
    int x;
    double v = 0;
    const Road *road;
    Car *front_car;
};

#endif
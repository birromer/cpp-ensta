#ifndef __CAR_H__
#define __CAR_H__

#include <math.h>
#include "road.h"

class Road;

class Car {
  public:
    Car(int x, double v, const Road *road);
    ~Car();
    int get_x();
    double get_v();
    void set(int x, double v);
    void draw();
    void stop();

  private:
    int x;
    double v;
    const Road *road;

};

#endif
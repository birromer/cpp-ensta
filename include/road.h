#ifndef __ROAD_H__
#define __ROAD_H__

#include "../include/vibes.h" // might need to change that
#include <vector>
#include <math.h>
#include "../include/car.h"

class Car;

class Road {
  public:
    Road(int length);
    ~Road();
    void draw(const std::vector<Car> &cars);
    int length() const;
    double radius() const;
    double sawtooth(double x);
    double circular_dist(double xm1, double x1);

  private:
    const int l;             // circunference of the route
};

#endif
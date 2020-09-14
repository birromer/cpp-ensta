#ifndef __ROAD_H__
#define __ROAD_H__

#include "../include/vibes.h" // might need to change that
#include <vector>
#include <math.h>
#include "../include/Car.h"

class Car;

double sawtooth(double x);
bool collision(Car& cm1, Car& c1);

class Road {
  public:
    Road(int length);
    ~Road();

    int length() const;
    double radius() const;

    void draw(const std::vector<Car> &cars) const;

    double circular_dist(const Car& cm1, const Car& c1) const;

  private:
    const int l;             // circunference of the route
};

#endif
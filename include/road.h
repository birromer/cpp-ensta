#ifndef __ROAD_H__
#define __ROAD_H__

#include "../include/vibes.h" // might need to change that
#include <math.h>

class Road {
  public:
    Road(int length);
    ~Road();
    void draw(double cx, double cy);
    int length();
    double radius();

  private:
    const int l;             // circunference of the route
};

#endif
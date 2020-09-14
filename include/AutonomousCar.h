#ifndef __AUTONOMOUS_CAR_H__
#define __AUTONOMOUS_CAR_H__

#include "../include/Car.h"
class Car;

class AutonomousCar : public Car {
  public:
    AutonomousCar(double x, double v, const Road *road);
    AutonomousCar(double x, const Road *road);
    double u(double d0, double v0) const;
  private:

};

#endif 
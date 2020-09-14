#include <iostream>
#include <unistd.h>
#include <vector>

#include "../include/road.h"
#include "../include/car.h"

void euler(double& x, double& v, double xdot, double vdot, double dt);

int main(int argc, char *argv[])
{
  const int n  = 15;                 // number of cars
  const int l = 100;                 // cirfunference of the road
  const double dt = 0.05;            // interval between evaluations
  const double d0 = l/n; // desired distance between cars (being read)
  const double v0 = 3.;              // desired speed

  Road road(l);
  std::vector<Car> cars;

  for (int i = 0; i < n; i++) {
    Car new_car(4*i, &road);
    cars.push_back(new_car);
  }

  for (int i = 0; i < n; i++)
    cars[i].set_front_car(cars[(i+1)%n]);

//  int u;
//  double xdot, vdot;
//  u = xdot = vdot = 1; // current reading, variation of pos and acceleration

//  for (int t = 0; t < 101; t++)
//  {
//    std::cout << "t: " << t << std::endl;
    road.draw((const std::vector<Car>&)cars);
    cars[0].draw();

    usleep(dt * 500000);
//  }

 //   f(x,v,u,xdot,vdot);
 //   euler(x,v,xdot,vdot,dt);
  return 0;
}

void euler(double& x, double& v, double xdot, double vdot, double dt)
{
  double dx = xdot*dt;
  double dv = vdot*dt;
  x = x + dx;  // x = xdot * dt
  v = v + dv;  // v = vdot * dt
}
#include <iostream>
#include <unistd.h>

#include "../include/road.h"
#include "../include/car.h"

void f(double x, double v, double u, double& xdot, double& vdot);

void euler(double& x, double& v, double xdot, double vdot, double dt);

int main(int argc, char *argv[])
{
  const int l = 100;                 // cirfunference of the road
  const int n  = 15;                 // number of cars
  const double dt = 0.05;            // interval between evaluations
  const double v0 = 3.;              // desired speed
  const double d0 = l/n; // desired distance between cars (being read)

  Road road(l);

//  int u, n;
//  double x, v, xdot, vdot, v0, d0;




  x  = v = 0;           // current position and speed
  u  = xdot = vdot = 1; // current reading, variation of pos and acceleration

  for (int t = 0; t < 101; t++)
  {
    std::cout << "t: " << t << std::endl;
    f(x,v,u,xdot,vdot);
    euler(x,v,xdot,vdot,dt);

    road.draw(0,0,r);
//    road.draw_robot(x,r);

    usleep(dt * 500000);
  }

  return 0;
}

void euler(double& x, double& v, double xdot, double vdot, double dt)
{
  double dx = xdot*dt;
  double dv = vdot*dt;
  x = x + dx;  // x = xdot * dt
  v = v + dv;  // v = vdot * dt
}

void f(double x, double v, double u, double& xdot, double& vdot)
{
  xdot = v;
  vdot = u; // according to equation (1)
}
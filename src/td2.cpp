#include <iostream>
#include <unistd.h>
#include <vector>

#include "../include/Road.h"
#include "../include/Car.h"
#include "../include/AutonomousCar.h"

void euler(double& x, double& v, double xdot, double vdot, double dt);

int main(int argc, char *argv[])
{
  const int n  = 15;                 // number of cars
  const int l = 100;                 // cirfunference of the road
  const double dt = 0.05;            // interval between evaluations
  const double d0 = l/n; // desired distance between cars (being read)
  const double v0 = 3.;              // desired speed

  Road road(l);
  std::vector<AutonomousCar> cars;

  for (int i = 0; i < n; i++) { // creates cars with defined position
    AutonomousCar new_car(4*i, &road);
    cars.push_back(new_car);
  }

  for (int i = 0; i < n; i++) // sets the front_car value
    cars[i].set_front_car(&cars[(i+1)%n]);

  double xdot, vdot;

  for (double t = 0; t < 101; t+=dt) {
//    std::cout << "t: " << t << std::endl;

    for (int i = 0; i < n; i++){ 
      //double u = cars[i].u(d0, v0) - i*0.04; // for testing collisions
      double u = cars[i].u(d0, v0); // autonomous car pd control

      cars[i].f(u,xdot,vdot); // evolution function
      cars[i].euler(xdot,vdot,dt); // step on the euler integration

      if (cars[i].collision()) { // stops if distance between cars smaller than car
        cars[i].stop();
      }
    }
    road.draw((const std::vector<Car>&)cars);
    usleep(dt * 500000);
  }

  return 0;
}
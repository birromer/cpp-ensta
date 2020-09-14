#include "../../include/AutonomousCar.h"

AutonomousCar::AutonomousCar(double x, double v, const Road *road) : Car(x,v,road) {

}

AutonomousCar::AutonomousCar(double x, const Road *road) : Car(x,road) {

}

double AutonomousCar::u(double d0, double v0) const {
  double proportional = (get_road()->circular_dist(*get_front_car(), *this) - d0) + (v0 - v());
  double derivative = (v() - get_front_car()->v());
  return proportional - derivative;
}
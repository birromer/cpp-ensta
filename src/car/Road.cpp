#include "../../include/Road.h"
#include <iostream>

Road::Road(int l) : l(l) {
  vibes::beginDrawing();
  vibes::newFigure("Jam");
  vibes::setFigureProperties("Jam",
                             vibesParams("x", 100, "y", 100,
                                        "width", 400, "height", 400)
                            );
  vibes::axisLimits(-20., 20., -20., 20.);
}

Road::~Road() {
  vibes::endDrawing();
}

int Road::length() const {
  return l;
}

double Road::radius() const{
    return length() / (2 * M_PI);  // radius based on desired circunference
}

void Road::draw(const std::vector<Car> &cars) const {
  double r = radius();
  double r1 = r - 2.5;        // two circles will be 2.5 units distant from the middle of the road
  double r2 = r + 2.5;        //  so that to have 5 width

  vibes::clearFigure("Jam");
  vibes::drawCircle(0, 0, r1);
  vibes::drawCircle(0, 0, r2);

  for (Car car : cars) {
    car.draw();
  }
}

double sawtooth(double x){
  return (2 * atan(tan(x/2)));
}

double Road::circular_dist(const Car& cm1, const Car& c1) const {
  double r = radius();
  double arg = (cm1.x() - c1.x())/r - M_PI;
  double di = r * (sawtooth(arg) + M_PI);
  return di;
}
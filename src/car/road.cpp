#include "../../include/road.h"
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

void Road::draw(const std::vector<Car> &cars) {
  double r = radius();
  double r1 = r - 2.5;        // two circles will be 2.5 units distant from the middle of the road
  double r2 = r + 2.5;        //  so that to have 5 width

  vibes::clearFigure("Jam");
  vibes::drawCircle(0, 0, r1);
  vibes::drawCircle(0, 0, r2);

//  for (Car car : cars) {
//    std::cout << "x: " << car.x() << " y: " << car.v() << std::endl;
//    car.draw();
//  }
}

double Road::sawtooth(double x){
  return (2 * atan(tan(x/2)));
}

double Road::circular_dist(double xm1, double x1) {
  double r = radius();
  double di = r * ( sawtooth(-M_PI + (xm1-x1)/r ) + M_PI);
  return di;
}

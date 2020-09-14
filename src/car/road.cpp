#include "../../include/road.h"

Road::Road(int length) : l(length) {
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

int Road::length() {
  return l;
}

double Road::radius() {
    return l / (2 * M_PI);  // radius based on desired circunference
}

void Road::draw(double cx, double cy)
{
  double r = radius();
  double r1 = r - 2.5;        // two circles will be 2.5 units distant from the middle of the road
  double r2 = r + 2.5;        //  so that to have 5 width

  vibes::clearFigure("Jam");
  vibes::drawCircle(cx, cy, r1);
  vibes::drawCircle(cx, cy, r2);
}
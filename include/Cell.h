#pragma once

#include <cstddef>
#include <cstdlib>
#include <cstdio>

class Cell {
  public:
    Cell(int x, int y);
    void add_neighb(Cell *c);
    static void add_neighb(Cell *c1, Cell *c2);

//  private:
    double m_x;
    double m_y;

    bool m_displayed = false;
    int m_nb_neighb = 0;
    Cell **m_neighb = NULL;
};

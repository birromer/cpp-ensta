#pragma once

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>

class Cell {
  public:
    Cell(int x, int y);
    ~Cell();
    void add_neighb(Cell *c);
    static void add_neighb(Cell *c1, Cell *c2);
    std::string toString();

//  private:
    double m_x;
    double m_y;

    bool m_explored = false;
    bool m_displayed = false;
    int m_nb_neighb = 0;
    Cell **m_neighb = NULL;
};

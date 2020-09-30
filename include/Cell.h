#ifndef __CELL_H_
#define __CELL_H_

#include <cstddef>

class Cell {
  public:
    Cell(int x, int y);
    void add_neighb(Cell *c);
    void add_neighb(Cell *c1, Cell *c2);

//  private:
    double m_x;
    double m_y;
    bool m_displayed;

    int m_nb_neighb = 0;
    Cell **m_neighb = NULL;
};

#endif // __CELL_H_

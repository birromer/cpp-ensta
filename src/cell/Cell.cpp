#include "../../include/Cell.h"

Cell::Cell(int x, int y) : m_x(x), m_y(y) {
   
}

void Cell::add_neighb(Cell *c) {
   bool already_added = false;

   if (this->m_neighb == NULL) {
      this->m_neighb = new Cell*[this->m_nb_neighb+1];

   }

   for (int i=0; i < this->m_nb_neighb; i++) {
      if (this->m_neighb[i]->m_x == c->m_x && this->m_neighb[i]->m_y == c->m_x)
         already_added = true;
   }

   if (!already_added) {
      this->m_nb_neighb += 1;
      this->m_neighb[m_nb_neighb-1] = c;

      c->add_neighb(this);
   }
}


void Cell::add_neighb(Cell *c1, Cell *c2) {
   c1->add_neighb(c2);
}

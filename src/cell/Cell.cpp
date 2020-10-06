#include "../../include/Cell.h"

Cell::Cell(int x, int y) : m_x(x), m_y(y) {
   
}


void Cell::add_neighb(Cell *c) {
   bool already_added = false;  // flag to check if neighbour have not already been added

   if (this->m_neighb == NULL)  // initializes neighbour list if first niehgbour
      this->m_neighb = new Cell*[1];

   for (int i=0; i < this->m_nb_neighb; i++) {  // searches for the case neighbour already exists
      if (this->m_neighb[i]->m_x == c->m_x && this->m_neighb[i]->m_y == c->m_x)
         already_added = true;
   }

   if (!already_added) {
      this->m_nb_neighb += 1;  // increases number of neighbours, as another is being added
      auto aux_m_neighb = this->m_neighb;  // temporary variable so that previous values are not lost in case
                                           // reallocation uses another area of the memory
      this->m_neighb = new Cell*[this->m_nb_neighb];  // allocates new memory space so that bigger array can be stored

      for (int i=0; i<m_nb_neighb-1; i++)  // as one cannot test if previous addresses were reused, previous elements
         m_neighb[i] = aux_m_neighb[i];    // are copied

      this->m_neighb[m_nb_neighb-1] = c;  // sets new neighbour
      c->add_neighb(this);                // repeats for neighbour
    }
}


void Cell::add_neighb(Cell *c1, Cell *c2) {
   c1->add_neighb(c2);
}

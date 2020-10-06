#include "../../include/Cell.h"
#include <iostream>

Cell::Cell(int x, int y) : m_x(x), m_y(y) {
   
}


void Cell::add_neighb(Cell *c) {
//   std::cout << "Add " << c->m_x << c->m_y << " to " << this->m_x << this->m_y << std::endl;
   bool first = false;

   for (int i=0; i < this->m_nb_neighb; i++) {  // searches for the case neighbour already exists
      if (this->m_neighb[i]->m_x == c->m_x && this->m_neighb[i]->m_y == c->m_y) {
//         std::cout << this->m_x << this->m_y << " already has " << c->m_x << c->m_y << std::endl;
//         std::cout << "Finished " << c->m_x << c->m_y << " to " << this->m_x << this->m_y << std::endl << std::endl;
         return;
      }
   }

   if (this->m_neighb == NULL) {  // initializes neighbour list if first niehgbour
      this->m_neighb = new Cell*[1];
      this->m_nb_neighb = 1;  // increases number of neighbours, as another is being added
      this->m_neighb[0] = c;  // sets new neighbour
      first = true;
//      std::cout << "Init " << this->m_x << this->m_y << std::endl;
   }

   if (!first) { // if it is the first time it has already incremented
      this->m_nb_neighb += 1;  // increases number of neighbours, as another is being added
      auto aux_m_neighb = this->m_neighb;  // temporary variable so that previous values are not lost in case
      // reallocation uses another area of the memory
      this->m_neighb = new Cell*[this->m_nb_neighb];  // allocates new memory space so that bigger array can be stored

      for (int i=0; i<m_nb_neighb-1; i++)  // as one cannot test if previous addresses were reused, previous elements
         m_neighb[i] = aux_m_neighb[i];    // are copied

      this->m_neighb[m_nb_neighb-1] = c;  // sets new neighbour


   }

//   std::cout << "Finished " << c->m_x << c->m_y << " to " << this->m_x << this->m_y << std::endl << std::endl;
   c->add_neighb(this);                // repeats for neighbour
}


void Cell::add_neighb(Cell *c1, Cell *c2) {
   c1->add_neighb(c2);
}

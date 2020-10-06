#include <iostream>
#include <unistd.h>

#include "../include/vibes.h" // might need to change those includes
#include "../include/Cell.h"

struct Maze {
    const Cell *init;  // the whole graph can be explored having the root
    const Cell *exit;
};

void draw_gate(const Cell *n1, const Cell *n2) {  // two immutable cells by reference
    vibes::drawBox(std::min(n1->m_x, n2->m_x) + 0.1, std::max(n1->m_x, n2->m_x) + 0.9, // the limits of the gate
                   std::min(n1->m_y, n2->m_y) + 0.1, std::max(n1->m_y, n2->m_y) + 0.9, // are the outmost elements
                   "lightGray[lightGray]");                                            // in each direction
}

void display_graph(Cell *cell) {
    // draws the box surrounding the cell
    vibes::drawBox(cell->m_x, cell->m_x + 1, cell->m_y, cell->m_y + 1, "[lightGray]");

    cell->m_displayed = true;

    for(int i = 0 ; i < cell->m_nb_neighb ; i++) {
        if(!cell->m_neighb[i]->m_displayed)  // calls the display function for every neighbour that hasn't been
            display_graph(cell->m_neighb[i]);  // displayed yed, effectively reaching every cell in the graph

        draw_gate(cell, cell->m_neighb[i]);
    }
}

Maze create_maze(const Cell *init, const Cell *exit) {
    Maze maze;
    maze.init = init;
    maze.exit = exit;
    return maze;
}

int main() {
    vibes::beginDrawing();
    vibes::newFigure("Maze");
    vibes::setFigureProperties("Maze",
                               vibesParams("x", 100, "y", 100,
                                          "width", 400, "height", 400)
                            );
    vibes::axisLimits(0-0.5, 4+0.5, 0-0.5, 4+0.5);

    Cell *ini = new Cell(0,0);

//    Cell *test = new Cell(9,90);
//    ini->add_neighb(test);

    display_graph(ini);

//    Maze maze = create_maze(4,4);
//    display_graph(ini);






    return 0;
}

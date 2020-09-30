#include <iostream>
#include <unistd.h>

#include "../include/vibes.h" // might need to change those includes
#include "../include/Cell.h"

typedef struct labyrinth {
    int size_x, size_y;
    Cell **cells;
} Maze;

void draw_gate(const Cell *n1, const Cell *n2) {
    vibes::drawBox(std::min(n1->m_x, n2->m_x) + 0.1, std::max(n1->m_x, n2->m_x) + 0.9,
                   std::min(n1->m_y, n2->m_y) + 0.1, std::max(n1->m_y, n2->m_y) + 0.9,
                   "lightGray[lightGray]");
}

void display_graph(Cell *cell) {
    vibes::drawBox(cell->m_x, cell->m_x + 1, cell->m_y, cell->m_y + 1, "[lightGray]");

    cell->m_displayed = true;

    for(int i = 0 ; i < cell->m_nb_neighb ; i++) {
        if(!cell->m_neighb[i]->m_displayed)
            display_graph(cell->m_neighb[i]);

        draw_gate(cell, cell->m_neighb[i]);
    }
}

Maze create_maze(int len_x, int len_y) {
    Maze maze;
    maze.size_x = len_x;
    maze.size_y = len_y;
    maze.cells = new Cell*[len_x*len_y];

    for (int i=0; i<len_x; i++) {
        for (int j=0; j<len_y; j++) {
            maze.cells[i+j] = new Cell(i,j);
        }
    }

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

    Cell *ini = new Cell(1,1);

    Cell *test = new Cell(1,2);

    ini->add_neighb(test);

    display_graph(ini);

    Maze maze = create_maze(4,4);
    display_graph(ini);






    return 0;
}

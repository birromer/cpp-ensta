#include <iostream>
#include <unistd.h>

#include "../include/vibes.h" // might need to change those includes
#include "../include/Cell.h"
#include "../include/Path.h"

struct Maze {
    Cell *init;  // the whole graph can be explored having the root
    Cell *exit;
};

void draw_gate(const Cell *n1, const Cell *n2);
void display_graph(Cell *cell);
void display(Maze m);
Maze create_maze(Cell *init, Cell *exit);

int main() {
    vibes::beginDrawing();
    vibes::newFigure("Maze");
    vibes::setFigureProperties("Maze",
                               vibesParams("x", 100, "y", 100,
                                          "width", 400, "height", 400)
                            );
    vibes::axisLimits(0-0.5, 4+0.5, 0-0.5, 4+0.5);

    // the cells
    Cell *c11 = new Cell(1,1);
    Cell *c12 = new Cell(1,2);
    Cell *c13 = new Cell(1,3);
    Cell *c14 = new Cell(1,4);
    Cell *c21 = new Cell(2,1);
    Cell *c22 = new Cell(2,2);
    Cell *c23 = new Cell(2,3);
    Cell *c24 = new Cell(2,4);
    Cell *c31 = new Cell(3,1);
    Cell *c32 = new Cell(3,2);
    Cell *c33 = new Cell(3,3);
    Cell *c34 = new Cell(3,4);
    Cell *c41 = new Cell(4,1);
    Cell *c42 = new Cell(4,2);
    Cell *c43 = new Cell(4,3);
    Cell *c44 = new Cell(4,4);

    // the connections
    Cell::add_neighb(c14,c24);
    Cell::add_neighb(c24,c34);
    Cell::add_neighb(c34,c44);
    Cell::add_neighb(c44,c43);
    Cell::add_neighb(c43,c42);
    Cell::add_neighb(c42,c41);
    Cell::add_neighb(c41,c31);
    Cell::add_neighb(c31,c32);
    Cell::add_neighb(c32,c22);
    Cell::add_neighb(c22,c23);
    Cell::add_neighb(c23,c33);
    Cell::add_neighb(c22,c21);
    Cell::add_neighb(c21,c11);
    Cell::add_neighb(c11,c12);
    Cell::add_neighb(c12,c13);

    display_graph(c21);

    Maze maze = create_maze(c13,c14);

    display(maze);

    return 0;
}

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

void display(Maze m) {
    display_graph(m.init);
    vibes::drawCircle(m.init->m_x+0.5, m.init->m_y+0.5, 0.3);
    vibes::drawCircle(m.exit->m_x+0.5, m.exit->m_y+0.5, 0.3);

}

Maze create_maze(Cell *init, Cell *exit) {
    Maze maze;
    maze.init = init;
    maze.exit = exit;
    return maze;
}

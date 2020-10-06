#include "../../include/Path.h"

Path::Path(const Cell *c) : m_c(c) {

}

Path::~Path() {
    if (this->m_next != NULL)
        delete this->m_next;

    delete this->m_c;
}

void Path::add_to_path(const Cell *c) {
    if (this->m_next == NULL)
        this->m_next = new Path(c);
    else
        this->m_next->add_to_path(c);
}

void Path::print_path() {
    if (this->m_next == NULL)
        printf("(%f,%f)\n", this->m_c->m_x, this->m_c->m_y);
    else {
        printf("(%f,%f) -> ", this->m_c->m_x, this->m_c->m_y);
        this->m_next->print_path();
    }
}

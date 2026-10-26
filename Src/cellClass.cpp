#include "cellClass.hpp"

void Cell::setAlive(bool value){
    m_alive = value;
}

bool Cell::isAlive(void) const{
    return m_alive;
}
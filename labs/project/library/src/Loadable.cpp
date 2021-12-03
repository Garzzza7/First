#include "Loadable.h"

unsigned Loadable::getCapacity(){}
unsigned Loadable::getSize(){}
Container& Loadable::at(int position){}
void Loadable::take(Container aContainer){}
Container Loadable::give(){}

bool Loadable::canTake()
{
    return getSize() < getCapacity();
}

bool Loadable::canGive()
{
    return getSize() > 0;
}
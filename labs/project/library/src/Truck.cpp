#include "Truck.h"

unsigned Truck::getCapacity()
{
    return MAX_TRAILER;
}

unsigned Truck::getSize()
{
    unsigned count = 0;
    for(Container container : trailer)
    {
        if(container.getNumber() != 0) ++count;
    }
    return count;
}

Container& Truck::at(int position)
{
    if(position < getCapacity())
    {
        std::cout << position << std::endl;
        return trailer[position];
    }
    else
    {
        throw std::out_of_range("The given position is out of bounds!");
    }
}

void Truck::take(Container aContainer)
{
    if(canTake())
    {
        for (int i = 0; i < getCapacity(); ++i)
        {
            if(trailer[i].getNumber() == 0)
            {
                trailer[i] = aContainer;
                break;
            }
        }
    }
    else
    {
        throw std::logic_error("The trailer is full and cannot take another container!");
    }
}

Container Truck::give()
{
    if(canGive())
    {
        for (int i = getCapacity() - 1; i >= 0; --i)
        {
            std::cout << i << std::endl;
            if(trailer[i].getNumber() != 0) {
                Container oldContainer, newContainer;
                oldContainer = trailer[i];
                trailer[i] = newContainer;
                return oldContainer;
            }
        }
    }
    else
    {
        throw std::logic_error("The trailer is empty and cannot give another container!");
    }
}
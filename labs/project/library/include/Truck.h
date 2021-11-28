//
// Created by student on 11/28/21.
//
#include "string.h"
#include "Loadable.h"

#ifndef OOPPROJECT_TRUCK_H
#define OOPPROJECT_TRUCK_H

#endif //OOPPROJECT_TRUCK_H

class Truck : public Loadable{

    Container[2] trailer;
public:
    Truck();
    unsigned getCapacity();
    unsigned getSize();
    Container& at(int index);
    void take(Container aContainer);
    Container give();

};


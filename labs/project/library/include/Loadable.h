//
// Created by student on 11/28/21.
//

#include "Container.h"

#ifndef OOPPROJECT_LOADABLE_H
#define OOPPROJECT_LOADABLE_H

#endif //OOPPROJECT_LOADABLE_H


class Loadable{
public:
    virtual unsigned getCapacity();
    virtual unsigned getSize();
    virtual Container& at(int index);
    virtual void take(Container aContainer);
    virtual Container give();
    bool canTake();
    bool canGive();

};
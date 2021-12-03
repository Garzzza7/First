#include "Container.h"

class Loadable{

public:
    virtual unsigned getCapacity();
    virtual unsigned getSize();
    virtual Container& at(int position);
    virtual void take(Container aContainer);
    virtual Container give();
    bool canTake();
    bool canGive();
};
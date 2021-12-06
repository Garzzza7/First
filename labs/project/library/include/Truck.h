#include "Loadable.h"

const unsigned MAX_TRAILER = 2;

class Truck : public Loadable{
    Container trailer[MAX_TRAILER] = {};
public:
    unsigned getCapacity();
    unsigned getSize();
    Container& at(int height);
    void take(Container aContainer);
    Container give();};
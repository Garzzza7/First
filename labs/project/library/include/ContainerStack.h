#include <iostream>
#include <vector>
#include "Loadable.h"

const unsigned MAX_HEIGHT = 10;

class ContainerStack : public Loadable{

    std::vector<Container> containers; //containers on the stack

    public:
        ContainerStack();
        unsigned getCapacity();
        unsigned getSize();
        Container& at(int height);
        void take(Container aContainer);
        Container give();

};
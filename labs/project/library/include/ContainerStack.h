#include <iostream>
#include <vector>
#include "Container.h"

const unsigned MAX_HEIGHT = 10;

class ContainerStack{

    std::vector<Container> containers; //containers on the stack

    public:
        ContainerStack();
        int getCapacity();
        int getSize();
        const Container& at(int height);
        void take(Container aContainer);
        Container give();

};
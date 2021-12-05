#include "ContainerStack.h"

ContainerStack::ContainerStack() {}

unsigned ContainerStack::getCapacity() {
    return MAX_HEIGHT;
}

unsigned ContainerStack::getSize() {
    return containers.size();
}

Container &ContainerStack::at(int height) {
    if(containers.size() < height) throw std::runtime_error("Attempted to access non-existing container from the stack!");
    return containers.at(height);
}

void ContainerStack::take(Container aContainer) {
    if(canTake())
    {
        containers.push_back(aContainer);
    }
    else
    {
        throw std::logic_error("Container stack capacity has been exceeded!");
    }
}

Container ContainerStack::give() {
    if(canGive())
    {
    Container c = containers.back();
    containers.pop_back();
    return c;
    }
    else
    {
        throw std::runtime_error("Container stack contains no containers!");
    }
}
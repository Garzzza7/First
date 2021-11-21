#include "ContainerStack.h"

ContainerStack::ContainerStack() {}

int ContainerStack::getCapacity() {
    return MAX_HEIGHT;
}

int ContainerStack::getSize() {
    return containers.size();
}

const Container &ContainerStack::at(int height) {
    if(containers.size() < height) throw std::runtime_error("Attempted to access non-existing container from the stack!");
    return containers.at(height);
}

void ContainerStack::take(Container aContainer) {
    if(containers.size() < MAX_HEIGHT)
    {
        containers.push_back(aContainer);
    }
    else
    {
        throw std::logic_error("Container stack capacity has been exceeded!");
    }
}

Container ContainerStack::give() {
    if(containers.size() <= 0) throw std::runtime_error("Container stack contains no containers!");
    Container c = containers.back();
    containers.pop_back();
    return c;
}
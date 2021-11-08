#include "ContainerStack.h"

ContainerStack::ContainerStack() {}

int ContainerStack::getCapacity() {
    return MAX_HEIGHT;
}

int ContainerStack::getSize() {
    return containers.size();
}

const Container &ContainerStack::at(int height) {
    return containers.at(height);
}

void ContainerStack::take(Container aContainer) {
    containers.push_back(aContainer);
}

Container ContainerStack::give() {
    Container c = containers.back();
    containers.pop_back();
    return c;
}
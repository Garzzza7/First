#include "Crane.h"

Crane::Crane() {
    Container c(0);
    container = c;
    position = 0;
}

bool Crane::isParked(){
    return position == -1;
}
bool Crane::isLoaded(){
    return container.getNumber() != 0 && position < 0;
}
bool Crane::isUnloaded(){
    return container.getNumber() == 0 && position < 0;
}
bool Crane::isWaitingEmpty(){
    return container.getNumber() == 0 && position >= 0;
}
bool Crane::isWaitingFull(){
    return  container.getNumber() != 0 && position >= 0;
}

void Crane::park(){
    if((isUnloaded() || isWaitingEmpty() )&& isWaitingEmpty()){
        position = -1;
    }else{
        throw std::logic_error("Tried to park a crane with container loaded!");
    }
}

void Crane::load(Container container){
    if(isUnloaded()){
        this->container = container;
    }else{
        throw std::logic_error("Tried to load a crane that isn't over the trailer or is already loaded!");
    }
}
Container Crane::unload(){
    if(isLoaded()){
        Container container1 = container;
        Container container2;
        container = container2;
        return container1;
    }else{
        throw std::logic_error("Tried to unload a crane that isn't above the trailer or is already unloaded!");
    }
}

void Crane::forward(int numSteps){
    if(position+numSteps<MAX_STACKS){
        position += numSteps;
    }else{
        throw std::logic_error("Tried to move the crane beyond the MAX_STACKS!");
    }
}
void Crane::backward(int numSteps){
    if(position-numSteps>=-3){
        position -= numSteps;
    }else{
    throw std::logic_error("Tried to move the crane in front of the trailer!");
    }
}
void Crane::pickUp(){
    if(isWaitingEmpty() && storage[position].getSize() != 0){
        container = storage[position].give();
    }else if(storage[position].getSize() != 0){
        throw std::logic_error("Tried to pick up a container with a loaded crane!");
    } else if(isWaitingEmpty()){
        throw std::logic_error("Tried to pick up a container from an empty container stack!");
    }
}
void Crane::putDown(){
    if(isWaitingFull() && storage[position].getSize() < storage->getCapacity()){
        Container c;
        storage[position].take(container);
        container = c;
    }
}
int Crane::getPosition(){
    return position;
}
Container& Crane::getContainer(){
    return container;
}
ContainerStack& Crane::stackAt(int position){
    if(position >= 0){
        return storage[position];
    }else{
        throw std::logic_error("Tried to access a stack at position that is out of bounds!");
    }
}
bool Crane::canPutDown(){
    return position >= 0 && stackAt(position).getSize() < stackAt(position).getCapacity();
}


void Crane::loadFrom (Loadable& truck)
{

}
void Crane::unloadOnto (Loadable& truck)
{

}
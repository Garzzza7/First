#include <iostream>
#include "Container.h"

Container::Container()
{
    number = 0;
    cargo = 0;
}
Container::Container(int num)
{
    number = num;
    cargo = 0;
}
Container::~Container()
{
    std::cout<<"Destructor"<<std::endl;
}
int Container::getNumber()
{
    return number;
}
void Container::setTare(double tareWeight)
{
    if(cargo+tareWeight<=maxWeight) {
        this->tareWeight = tareWeight;
    }
    else{
        std::cout<<"The tare weight given is exceeding the max weight!"<<std::endl;
    }
}
double Container::getTare()
{
    return tareWeight;
}
void Container::setMaxWeight(double maxWeight)
{
    if(cargo+tareWeight<=maxWeight) {
        this->maxWeight = maxWeight;
    }
    else{
        std::cout << "The max weight set is lighter than cargo and tare weight!" << std::endl;
    }
}
double Container::getMaxWeight()
{
    return maxWeight;
}
void Container::setStrength(double strength)
{
    this->strength=strength;
}
double Container::getStrength()
{
    return strength;
}
double Container::getGrossWeight()
{
    return tareWeight+cargo;
}
double Container::getNetWeight()
{
    return cargo;
}
double Container::getMaxCargo()
{
        return maxWeight-tareWeight;
}

void Container::loadCargo(double amount)
{
    cargo += amount;
    if(cargo+tareWeight>maxWeight) cargo = maxWeight-tareWeight;
}
void Container::unloadCargo(double amount)
{
    cargo -= amount;
    if(cargo<0) cargo = 0;
}
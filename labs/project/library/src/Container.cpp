//
// Created by student on 10/25/21.
//
#include <iostream>

#include "Container.h"
/*
Container::Container(int number , double tareWeight , double maxWeight , double strength, double cargo)
{
    std::cout<<"Constructor"<<std::endl;
}
*/
Container::Container()
{
    number=0;
}
Container::Container(int)
{
    number;
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
    this->tareWeight=tareWeight;
}
double Container::getTare()
{
    return tareWeight;
}
void Container::setMaxWeight(double maxWeight)
{
    this->maxWeight=maxWeight;
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
}
void Container::unloadCargo(double amount)
{
    cargo -= amount;
}
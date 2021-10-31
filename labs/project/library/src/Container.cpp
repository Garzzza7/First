//
// Created by student on 10/25/21.
//
#include <iostream>

#include "Container.h"



Container::Container()
{
    int number=0;
}
Container::Container(int number)
{

}
int Container::getNumber()
{

}

double Container::getTare()
{


}

double Container::getMaxWeight()
{

}
void Container::setMaxWeight(double maxWeight)
{

}
double Container::getStrength()
{

}
void Container::setStrength(double strength)
{

}
double Container::getGrossWeight()
{

}
double Container::getNetWeight()
{

}
double Container::getMaxCargo()
{
    return maxWeight+tareWeight;
}

void Container::loadCargo(double amount)
{

}
void Container::unloadCargo(double amount)
{

}


#include <iostream>
#include "Container.h"

using namespace std;

int main ()
{

return 0;
}

void display(Container c)
{
    cout << "Container number: " << c.getNumber() << "\n";
    cout << "Container tare weight: " << c.getTare() << "\n";
    cout << "Container max weight: " << c.getMaxWeight() << "\n";
    cout << "Container strength: " << c.getStrength() << "\n";
    cout << "Container gross weight: " << c.getGrossWeight() << "\n";
    cout << "Container net weight: " << c.getNetWeight() << "\n";
    cout << "Container max cargo: " << c.getMaxCargo() << "\n";

}

void display(Container* p)
{
    Container c = *p;
    display(c);
}

void testLocalObject()
{
    Container container(1);
    container.setTare(1001.32);
    container.setMaxWeight(3929.11);
    container.setStrength(442.992);

    display(container);
}

void displayCargo(Container& c)
{
    cout << "Current cargo weight (net weight): " << c.getNetWeight();
}

void loadAndSend(Container& c, double goods)
{
    displayCargo(c);
    c.loadCargo(goods);
    displayCargo(c);
}

Container* prepare(int number, double goods)
{
    Container* c = new Container(number);
    c->loadCargo(goods);
    return c;
}

void testDynamicObject()
{
    Container *c = prepare(4, 1020.32);
    display(c);
    delete(c);
}
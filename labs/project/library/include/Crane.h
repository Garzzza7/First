#include <iostream>
#include "ContainerStack.h"

constexpr unsigned MAX_STACKS = 5;

class Crane{

    ContainerStack storage[MAX_STACKS];
    Container container;
    int position;

public:
    Crane();

    bool isParked();
    bool isLoaded();
    bool isUnloaded();
    bool isWaitingEmpty();
    bool isWaitingFull();

    void park();

    //void load(Container container);
    //Container unload();
    void loadFrom (Loadable& truck);
    void unloadOnto (Loadable& truck);

    void forward(int numSteps);
    void backward(int numSteps);

    void pickUp();
    void putDown();

    int getPosition();
    Container& getContainer();
    ContainerStack& stackAt(int position);

    bool canPutDown();


};
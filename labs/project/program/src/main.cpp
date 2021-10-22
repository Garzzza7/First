#include <cstdlib>
#include <ctime>

#include "World.h"

using namespace std;

int main() {

    srand(time(NULL));

    World world;
    world.startSimulation(5);

    return EXIT_SUCCESS;
}
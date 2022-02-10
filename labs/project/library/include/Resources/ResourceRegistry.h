#ifndef OOPPROJECT_RESOURCEREGISTRY_H
#define OOPPROJECT_RESOURCEREGISTRY_H

#include <mutex>
#include <map>
#include "Resource.h"

enum ResourceID{
    AIR_TILE_ID = 0,
    GROUND_TILE_ID = 1,
    BRICK_TILE_ID = 2,
    BLOCK_TILE_ID = 3,
    GOOMBA_ENTITY_ID = 4,
    PPLANT_ENTITY_ID = 5,
    COIN_ENTITY_ID = 6
};

class ResourceRegistry{
    ResourceID id;

    //Singleton stuff:
    static ResourceRegistry * instance;
    static std::mutex mutex;

    //Map of resources
    std::map<unsigned int, Resource*> resourceMap;

protected:
    ResourceRegistry();
    ~ResourceRegistry() {}

public:

    //Constant variables:

    const std::string relativeTexturePath{"../../textures/"};
    const unsigned int tileSize{16};

    //Singleton stuff:

    ResourceRegistry(ResourceRegistry &other) = delete;

    void operator=(const ResourceRegistry &) = delete;

    static ResourceRegistry *GetInstance();


    void initObjects();
    void deleteObjects();
    ResourceID getID() const {return id;}

    unsigned int getTileSize();
    Resource * getPresetById(unsigned int id);

};

#endif //OOPPROJECT_RESOURCEREGISTRY_H

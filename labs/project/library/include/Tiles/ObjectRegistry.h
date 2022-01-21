//
// Created by specklew on 20.01.2022.
//

#ifndef OOPPROJECT_OBJECTREGISTRY_H
#define OOPPROJECT_OBJECTREGISTRY_H

#include <mutex>
#include "ObjectBase.h"


class ObjectRegistry{

    static ObjectRegistry * instance;
    static std::mutex mutex;

    std::vector<ObjectBase*> objectBases;
    const unsigned int tileSize{32};

protected:
    ObjectRegistry();
    ~ObjectRegistry() {}

public:

    //Singleton stuff:

    ObjectRegistry(ObjectRegistry &other) = delete;

    void operator=(const ObjectRegistry &) = delete;

    static ObjectRegistry *GetInstance();

    //My stuff lol:

    void initObjects();
    void deleteObjects();

    unsigned int getTileSize();
    ObjectBase * getPresetById(int id);

};

#endif //OOPPROJECT_OBJECTREGISTRY_H

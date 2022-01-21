//
// Created by specklew on 20.01.2022.
//

#ifndef OOPPROJECT_TILEREGISTRY_H
#define OOPPROJECT_TILEREGISTRY_H

#include <mutex>
#include "TilePreset.h"

class TileRegistry{

    static TileRegistry * instance;
    static std::mutex mutex;

    std::vector<TilePreset*> tilePresets;

protected:
    TileRegistry();
    ~TileRegistry() {}

public:

    //Singleton stuff:

    TileRegistry(TileRegistry &other) = delete;

    void operator=(const TileRegistry &) = delete;

    static TileRegistry *GetInstance();

    //My stuff lol:

    void initTiles();
    void deleteTiles();

    TilePreset * getPresetById(int id);

};

#endif //OOPPROJECT_TILEREGISTRY_H

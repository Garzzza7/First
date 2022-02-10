#include <boost/test/unit_test.hpp>
/*
#include "Entities/Entity.h"
#include "Entities/EntityFactory.h"
#include "Entities/Goomba.h"
#include "Entities/PPlant.h"
#include "Resources/Resource.h"
#include "Resources/ResourceRegistry.h"
#include "Tiles/Tile.h"
#include "Game.h"
#include "Level.h"
*/
#include "Player.h"

BOOST_AUTO_TEST_SUITE(PlayerTest)
    BOOST_AUTO_TEST_CASE(test1) {
        Player * player = new Player(0,0);
        BOOST_REQUIRE_EQUAL(player->getHP(), 5);
        delete player;
    }



BOOST_AUTO_TEST_SUITE_END()
#include <boost/test/unit_test.hpp>
/*
#include "Enemies/Enemy.h"
#include "Enemies/EnemyFactory.h"
#include "Enemies/Goomba.h"
#include "Enemies/PPlant.h"
#include "Resources/Resource.h"
#include "Resources/ResourceRegistry.h"
#include "Tiles/Tile.h"
#include "Game.h"
#include "Level.h"
*/
#include "Player.h"

BOOST_AUTO_TEST_SUITE(PlayerTest)
    BOOST_AUTO_TEST_CASE(test1) {
        Player * player;
        BOOST_REQUIRE_EQUAL(player->getHP(), 5);
    }



BOOST_AUTO_TEST_SUITE_END()
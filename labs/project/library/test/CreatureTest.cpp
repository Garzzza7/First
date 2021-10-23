//
// Created by student on 10/23/21.
//

#include <boost/test/unit_test.hpp>

#include "Creature.h"

BOOST_AUTO_TEST_SUITE(CretureTestSuite)

    BOOST_AUTO_TEST_CASE(CreatureDistanceToTest1) {
        Creature creatureA(2.0,2.0,2);
        Creature creatureB(2.0,2.0,2);
        BOOST_REQUIRE_EQUAL(creatureA.distanceTo(&creatureB), 0.0);
    }
    BOOST_AUTO_TEST_CASE(CreatureDistanceToTest2) {
        Creature creatureA(2.0,2.0,2);
        Creature creatureB(4.0,2.0,1);
        BOOST_REQUIRE_EQUAL(creatureA.distanceTo(&creatureB), 2.0);
    }
    BOOST_AUTO_TEST_CASE(CreatureDistanceToTest3) {
        Creature creatureA(0.0,2.0,2);
        Creature creatureB(4.0,2.0,2);
        BOOST_REQUIRE_EQUAL(creatureA.distanceTo(&creatureB), 4.0);
    }
    BOOST_AUTO_TEST_CASE(CreatureDistanceToTest4) {
        Creature creatureA(0.0,0.0,2);
        Creature creatureB(3.0,4.0,2);
        BOOST_REQUIRE_EQUAL(creatureA.distanceTo(&creatureB), 5.0);
    }
    BOOST_AUTO_TEST_CASE(CreatureDistanceToTest5) {
        Creature creatureA(5.0,2.0,2);
        Creature creatureB(10.0,14.0,2);
        BOOST_REQUIRE_EQUAL(creatureA.distanceTo(&creatureB), 13.0);
    }
    BOOST_AUTO_TEST_CASE(CreatureDistanceToTest6) {
        Creature creatureA(5.0,2.0,2);
        Creature creatureB(10.0,14.0,2);
        BOOST_REQUIRE_EQUAL(creatureA.distanceTo(&creatureB), creatureB.distanceTo(&creatureA));
    }

BOOST_AUTO_TEST_SUITE_END()
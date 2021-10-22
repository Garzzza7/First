#include <boost/test/unit_test.hpp>
#include <Monster.h>

BOOST_AUTO_TEST_SUITE(MonsterTestSuite)

    BOOST_AUTO_TEST_CASE( HumanFirstNameCase ) {
        Monster monster(2.0,2.0,2);
        BOOST_REQUIRE_EQUAL(monster.getXPos(), 2.0);
    }

BOOST_AUTO_TEST_SUITE_END()


#include <boost/test/unit_test.hpp>

#include "Crane.h"

BOOST_AUTO_TEST_SUITE(TestCraneSuite)

    BOOST_AUTO_TEST_CASE(GetInitialConditionsWhenCraneInitializedEmpty) {
        Crane crane;
        BOOST_REQUIRE_EQUAL(crane.getPosition(), 0);
        BOOST_REQUIRE_EQUAL(crane.getContainer().getNumber(), 0);
        for (int i = 0; i < 5; ++i) {
            BOOST_REQUIRE_EQUAL(crane.stackAt(i).getSize(), 0);
        }
    }

BOOST_AUTO_TEST_SUITE_END()
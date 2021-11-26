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
    BOOST_AUTO_TEST_CASE(GetErrorsWhenMovingBeyondContainerStacks) {
        Crane crane;
        BOOST_REQUIRE_THROW(crane.forward(6), std::logic_error);
    }
    BOOST_AUTO_TEST_CASE(GetErrorsWhenMovingInFrontOfTrailer) {
        Crane crane;
        BOOST_REQUIRE_THROW(crane.backward(4), std::logic_error);
    }
    BOOST_AUTO_TEST_CASE(GetTrueWhenIsParked) {
        Crane crane;
        crane.park();
        BOOST_REQUIRE_EQUAL(crane.isParked(), true);
    }
    BOOST_AUTO_TEST_CASE(GetErrorWhenTryingToParkWhileTransportingContainer) {
        Crane crane;
        crane.backward(2);
        Container container(1);
        crane.load(container);

        BOOST_REQUIRE_THROW(crane.park(), std::logic_error);
    }

BOOST_AUTO_TEST_SUITE_END()
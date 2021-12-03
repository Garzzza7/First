#include <boost/test/unit_test.hpp>

#include "Truck.h"

BOOST_AUTO_TEST_SUITE(TestTruckSuite)

    //1
    BOOST_AUTO_TEST_CASE(IsInitiallyEmpty) {
            Truck truck;
            BOOST_REQUIRE_EQUAL(truck.getSize(), 0);
            Container container(1);
            truck.take(container);
            BOOST_REQUIRE_EQUAL(truck.getSize(), 1);
    }

BOOST_AUTO_TEST_SUITE_END()
#include <boost/test/unit_test.hpp>

#include "Container.h"

BOOST_AUTO_TEST_SUITE(TestContainerSuite)

    BOOST_AUTO_TEST_CASE(HasNumberWhenWithParameter) {
        Container container(1);
        BOOST_REQUIRE_EQUAL(container.getNumber(), 1);
    }

    BOOST_AUTO_TEST_CASE(HasNumber0WhenNoParameters) {
        Container container;
        BOOST_REQUIRE_EQUAL(container.getNumber(), 0);
    }

    BOOST_AUTO_TEST_CASE(EmptyWhenNoInputs) {
        Container container;
        BOOST_REQUIRE_EQUAL(container.getGrossWeight(), container.getTare());
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0);
        double result = container.getMaxWeight() - container.getTare();
        BOOST_REQUIRE_EQUAL(container.getMaxCargo(), result);
    }

    BOOST_AUTO_TEST_CASE(ContainsCargoWhenLoaded) {
        Container container;
        container.setMaxWeight(500.0);
        container.loadCargo(420.69);
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 420.69);
    }

    BOOST_AUTO_TEST_CASE(LoadAboveMaxWeight) {
        Container container;
        container.setMaxWeight(1000.0);
        container.loadCargo(1100.0);
        BOOST_REQUIRE_EQUAL(container.getNetWeight(),1000.0);
    }
    BOOST_AUTO_TEST_CASE(UnloadMoreThanContains) {
        Container container;
        container.unloadCargo(5.0);
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0);
    }

BOOST_AUTO_TEST_SUITE_END()
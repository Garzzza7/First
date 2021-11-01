#include <boost/test/unit_test.hpp>

#include "Container.h"

BOOST_AUTO_TEST_SUITE(TestContainerConstructorWithNumber)

    BOOST_AUTO_TEST_CASE(ConstructorWithNumber) {
        Container container(1);
        BOOST_REQUIRE_EQUAL(container.getNumber(), 1);
    }

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(TestContainerConstructorWithout)

        BOOST_AUTO_TEST_CASE(ConstructorWithout) {
        Container container;
        BOOST_REQUIRE_EQUAL(container.getNumber(), 0);
    }

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(TestEmptyContainer)

        BOOST_AUTO_TEST_CASE(ContainerGrossWeight) {
        Container container;
        BOOST_REQUIRE_EQUAL(container.getGrossWeight(), container.getTare());
    }
        BOOST_AUTO_TEST_CASE(ContainerNetWeight) {
        Container container;
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0);
    }
        BOOST_AUTO_TEST_CASE(ContainerMaxWeight) {
        Container container;
        double result = container.getMaxWeight() - container.getTare();
        BOOST_REQUIRE_EQUAL(container.getMaxCargo(), result);
    }

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(TestLoadCargoBelowMax)

        BOOST_AUTO_TEST_CASE(ContainerLoad) {
        Container container;
        container.loadCargo(420.69);
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 420.69);
    }

BOOST_AUTO_TEST_SUITE_END()
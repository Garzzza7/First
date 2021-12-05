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
    //2
    BOOST_AUTO_TEST_CASE(GetCorrectSizeWhenStackHasContainers) {
        Truck truck;
        Container c[2];
        for(int i = 0; i < 2; i++){
            truck.take(c[i]);
        }
        BOOST_REQUIRE_EQUAL(truck.getSize(), 2);
    }

    //3
    BOOST_AUTO_TEST_CASE(GetLogicErrorWhenStackExceedsCapacity) {
        Truck truck;
        Container c[3];
        for(int i = 0; i < 3; i++){
            truck.take(c[i]);
        }
        BOOST_CHECK_THROW(
                truck.take(c[3]),
                std::logic_error);
    }

    //4
    BOOST_AUTO_TEST_CASE(GetEmptyWhenLastContainerFromTrailerRemoved) {
        Truck truck;
        Container container(12);

        truck.take(container);

        BOOST_REQUIRE_EQUAL(truck.give().getNumber(), container.getNumber());
        BOOST_REQUIRE_EQUAL(truck.getSize(), 0);
    }
/*
    //5
    BOOST_AUTO_TEST_CASE(Get1ContainerAfterRemovalFrom1ItemFromTrailer) {
        Truck truck;
        for (int i = 0; i < 3; i++) {
            Container container(i);
            stack.take(container);
        }
        BOOST_REQUIRE_EQUAL(stack.getSize(),3);
        Container container = stack.at(2);
        BOOST_REQUIRE_EQUAL(container.getNumber(), 2);
        stack.give();
        BOOST_REQUIRE_EQUAL(stack.getSize(),2);
    }
*/
    //6
    BOOST_AUTO_TEST_CASE(GetTheSameContainerRegistryNumberWhenUsingAtAndGetNumber) {
        Truck truck;
        for (int i = 0; i < 2; i++) {
            Container container(i);
            truck.take(container);
        }
        for(int i = 0; i < 2; i++) {
            Container container = truck.at(i);
            BOOST_REQUIRE_EQUAL(i, container.getNumber());
        }
    }

    //7
    BOOST_AUTO_TEST_CASE(GetARuntimeErrorWhenRemovingFromAnEmptyTrailer){
        Truck truck;
        BOOST_REQUIRE_EQUAL(truck.getSize(), 0);
        BOOST_REQUIRE_THROW(
                truck.give(),
                std::runtime_error);

    }

    //8
    BOOST_AUTO_TEST_CASE(GetExceptionWhenAttemptingToAccessNonExistingContainerFromTrailer) {
        Truck truck;

        for(int i =0; i < 2; i++){
            Container container(i);
            truck.take(container);
        }

        BOOST_REQUIRE_THROW(
                truck.at(5),
                std::runtime_error);
    }
BOOST_AUTO_TEST_SUITE_END()
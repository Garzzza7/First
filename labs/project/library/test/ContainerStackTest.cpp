#include <boost/test/unit_test.hpp>

#include "ContainerStack.h"

BOOST_AUTO_TEST_SUITE(TestContainerStackSuite)
//1
    BOOST_AUTO_TEST_CASE(IsInitiallyEmpty) {
        ContainerStack stack;
        BOOST_REQUIRE_EQUAL(stack.getSize(), 0);
        Container container;
        stack.take(container);
        BOOST_REQUIRE_EQUAL(stack.getSize(), 1);
    }
//2
    BOOST_AUTO_TEST_CASE(GetCorrectSizeWhenStackHasContainers) {
        ContainerStack stack;
        Container c[9];
        for(int i = 0; i < 9; i++){
            stack.take(c[i]);
        }
        BOOST_REQUIRE_EQUAL(stack.getSize(), 9);
    }
//3
    BOOST_AUTO_TEST_CASE(LoadMoreThanCapacity) {
            ContainerStack stack;
            double result= stack.getCapacity()-stack.getSize();
            BOOST_CHECK(result>=0);
    }
//4
    BOOST_AUTO_TEST_CASE(RemovalFromA1ItemStack) {
            ContainerStack stack;
            Container container;
            BOOST_REQUIRE_EQUAL(stack.getSize(),1);
            BOOST_REQUIRE_EQUAL(1,container.getNumber());
            stack.give();
            BOOST_REQUIRE_EQUAL(stack.getSize(),0);
    }

//5
    BOOST_AUTO_TEST_CASE(RemovalFromA3ItemStack) {
        ContainerStack stack;
        Container container;
        BOOST_REQUIRE_EQUAL(stack.getSize(),3);
        BOOST_REQUIRE_EQUAL(3,container.getNumber());
        stack.give();
        BOOST_REQUIRE_EQUAL(stack.getSize(),2);
    }
//6
    BOOST_AUTO_TEST_CASE(CheckIfConstLoaded) {
        ContainerStack stack;
        int i;
        Container c[9];
        for(i = 0; i < 9; i++) {
            stack.take(c[i]);
            BOOST_REQUIRE_EQUAL(c[i].getNumber(), stack.at(i));
        }
    }
//7
    BOOST_AUTO_TEST_CASE(RemoveFromEmpty) {
        ContainerStack stack;
        Container container;

        BOOST_REQUIRE_EQUAL(stack.getSize(), 0);
        BOOST_REQUIRE_EQUAL(stack.give(),stack.getSize());

    }
//8
    BOOST_AUTO_TEST_CASE(ExceedTheNmber) {
        ContainerStack stack;
        Container container;
        BOOST_REQUIRE_EQUAL(stack.getSize(),3);
        BOOST_REQUIRE_EQUAL(3,container.getNumber());
        stack.give();
        BOOST_REQUIRE_EQUAL(stack.getSize(),2);
    }

    BOOST_AUTO_TEST_CASE(GetLogicErrorWhenStackExceedsCapacity) {
        ContainerStack stack;
        Container c[11];
        for(int i = 0; i < 10; i++){
            stack.take(c[i]);
        }
        BOOST_CHECK_THROW(
                stack.take(c[11]),
                std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(GetEmptyWhenLastContainerFromStackRemoved) {
        ContainerStack stack;
        Container container(12);

        stack.take(container);

        BOOST_REQUIRE_EQUAL(stack.give().getNumber(), container.getNumber());
        BOOST_REQUIRE_EQUAL(stack.getSize(), 0);
    }

    //Test 8:
    BOOST_AUTO_TEST_CASE(GetExceptionWhenAttemptingToAccessNonExistingContainerFromStack) {
        ContainerStack stack;

        for(int i =0; i < 4; i++){
            Container container(i);
            stack.take(container);
        }

        BOOST_REQUIRE_THROW(
                stack.at(5),
                std::runtime_error);
    }


BOOST_AUTO_TEST_SUITE_END()
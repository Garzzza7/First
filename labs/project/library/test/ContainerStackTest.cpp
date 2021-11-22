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

    //4
    BOOST_AUTO_TEST_CASE(GetEmptyWhenLastContainerFromStackRemoved) {
        ContainerStack stack;
        Container container(12);

        stack.take(container);

        BOOST_REQUIRE_EQUAL(stack.give().getNumber(), container.getNumber());
        BOOST_REQUIRE_EQUAL(stack.getSize(), 0);
    }

    //5
    BOOST_AUTO_TEST_CASE(Get2ContainersAfterRemovalFromA3ItemStack) {
        ContainerStack stack;
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

    //6
    BOOST_AUTO_TEST_CASE(GetTheSameContainerRegistryNumberWhenUsingAtAndGetNumber) {
        ContainerStack stack;
        for (int i = 0; i < 9; i++) {
            Container container(i);
            stack.take(container);
        }
        for(int i = 0; i < 9; i++) {
            Container container = stack.at(i);
            BOOST_REQUIRE_EQUAL(i, container.getNumber());
        }
    }

    //7
    BOOST_AUTO_TEST_CASE(GetARuntimeErrorWhenRemovingFromAnEmptyStack) {
        ContainerStack stack;

        BOOST_REQUIRE_EQUAL(stack.getSize(), 0);
        BOOST_REQUIRE_THROW(
                stack.give(),
                std::runtime_error);

    }

    //8
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
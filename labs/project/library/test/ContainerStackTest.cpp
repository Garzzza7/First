#include <boost/test/unit_test.hpp>

#include "ContainerStack.h"

BOOST_AUTO_TEST_SUITE(TestContainerStackSuite)

    BOOST_AUTO_TEST_CASE(IsInitiallyEmpty) {
        ContainerStack stack;
        BOOST_REQUIRE_EQUAL(stack.getSize(), 0);
        Container container;
        stack.take(container);
        BOOST_REQUIRE_EQUAL(stack.getSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(GetCorrectSizeWhenStackHasContainers) {
        ContainerStack stack;
        Container c[9];
        for(int i = 0; i < 9; i++){
            stack.take(c[i]);
        }
        BOOST_REQUIRE_EQUAL(stack.getSize(), 9);
    }
    BOOST_AUTO_TEST_CASE(LoadMoreThanCapacity)
            ContainerStack stack;
            BOOST_REQUIRE_EQUAL(stack.getCapacity);


            )

BOOST_AUTO_TEST_SUITE_END()
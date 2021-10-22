#include <boost/test/unit_test.hpp>

#include "Human.h"

BOOST_AUTO_TEST_SUITE(HumanSuiteCorrect)

BOOST_AUTO_TEST_CASE(HumanFirstNameCase) {
    Human human("Adam", 2.0,2.0,2);
    BOOST_REQUIRE_EQUAL(human.getName(), "Adam");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(HumanSuiteFailure)

BOOST_AUTO_TEST_CASE(HumankFirstNameRequire) {
    Human human("Adam",2.0,2.0,2);
    BOOST_REQUIRE_EQUAL(human.getName(), "Error"); //fatal error - end test case
    BOOST_REQUIRE_EQUAL(human.getName(), "Adam"); //not invoked due to previous fatal error
}

BOOST_AUTO_TEST_CASE(HumanFirstNameCheck) {
    Human human("Adam", 2.0,2.0,2);
    BOOST_CHECK_EQUAL(human.getName(), "Error"); //error - continue testing
    BOOST_CHECK_EQUAL(human.getName(), "Adam");
}

BOOST_AUTO_TEST_SUITE_END()

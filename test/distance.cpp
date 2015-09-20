#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Distances
#include "../src/LevenshteinCalculator.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(add_one) {
    LevenshteinCalculator calculator("ant");
    BOOST_CHECK_EQUAL(calculator.compare("aunt"), 1);
}

BOOST_AUTO_TEST_CASE(add_five) {
    LevenshteinCalculator calculator("Sam");
    BOOST_CHECK_EQUAL(calculator.compare("Samantha"), 5);
}

BOOST_AUTO_TEST_CASE(remove_five) {
    LevenshteinCalculator calculator ("Samantha");
    BOOST_CHECK_EQUAL(calculator.compare("Sam"), 5);
}

BOOST_AUTO_TEST_CASE(add_replace) {
    LevenshteinCalculator calculator("Flomax");
    BOOST_CHECK_EQUAL(calculator.compare("Volmax"), 3);
}

BOOST_AUTO_TEST_CASE(add_replace_2) {
    LevenshteinCalculator calculator("kitten");
    BOOST_CHECK_EQUAL(calculator.compare("sitting"), 3);
}

BOOST_AUTO_TEST_CASE(replace_remove) {
    LevenshteinCalculator calculator("Saturday");
    BOOST_CHECK_EQUAL(calculator.compare("Sunday"), 3);
}


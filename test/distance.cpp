#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Distances
#include "../src/LevenshteinSorter.h"
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

BOOST_AUTO_TEST_CASE(sort_sorted) {
    vector<string> lst = {"a","aa","aaa","aaaa"};
    LevenshteinSorter s("a");
    s.sortVector(lst);
    vector<string> res = {"a","aa","aaa","aaaa"};
    for(int i = 0; i < res.size(); i++) {
        BOOST_CHECK_EQUAL(lst[i], res[i]);
    }
}


BOOST_AUTO_TEST_CASE(sort_reversed) {
    vector<string> lst = {"aaaa","aaa","aa", "a",};
    LevenshteinSorter s("a");
    s.sortVector(lst);
    vector<string> res = {"a","aa","aaa","aaaa"};
    for(int i = 0; i < res.size(); i++) {
        BOOST_CHECK_EQUAL(lst[i], res[i]);
    }
}

BOOST_AUTO_TEST_CASE(sort_shuffled) {
    vector<string> lst = {"sydney","sand","sample", "dendy",};
    LevenshteinSorter s("sendy");
    s.sortVector(lst);
    vector<string> res = {"dendy","sand","sydney","sample"};
    for(int i = 0; i < res.size(); i++) {
        BOOST_CHECK_EQUAL(lst[i], res[i]);
    }
}

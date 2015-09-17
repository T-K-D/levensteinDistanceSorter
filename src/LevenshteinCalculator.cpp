#include "LevenshteinCalculator.h"

int LevenshteinCalculator::compare(std::string obj) {
    //memoization
    if (compareResults.count(obj) > 0){
        return compareResults[obj];
    }
    //actual calculation

    return 0;
}

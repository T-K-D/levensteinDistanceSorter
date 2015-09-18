#ifndef LEVENSTEINDISTANCESORTER_LEVENSHTEINSORTER_H
#define LEVENSTEINDISTANCESORTER_LEVENSHTEINSORTER_H

#include <string>
#include "LevenshteinCalculator.h"
#include <vector>
using namespace std;

class LevenshteinSorter {
public:
    LevenshteinSorter(string base)
    :_base(base),calculator(base){}

    vector<string> sort(vector<string> base);

private:
    string _base;
    LevenshteinCalculator calculator;
};


#endif //LEVENSTEINDISTANCESORTER_LEVENSHTEINSORTER_H

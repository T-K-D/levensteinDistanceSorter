#ifndef LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H
#define LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

#include <string>
#include <unordered_map>
using namespace std;
class LevenshteinCalculator {

public:
    LevenshteinCalculator(string compareSource)
    : _compareSource(compareSource){}
    int compare(string obj);
private:
    string _compareSource;
    unordered_map<string,int> compareResults;
};


#endif //LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

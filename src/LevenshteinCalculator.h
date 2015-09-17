#ifndef LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H
#define LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

#include <string>
#include <unordered_map>
using namespace std;
class LevenshteinCalculator {

public:
    LevenshteinCalculator(string comparator)
    :_comparator(comparator){}
    int compare(string obj);

    bool operator< (string obj) { return (this->compare(obj) <  0); }
    bool operator> (string obj) { return (this->compare(obj) >  0); }
    bool operator==(string obj) { return (this->compare(obj) == 0); }
private:
    string _comparator;
    unordered_map<string,int> compareResults;
};


#endif //LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

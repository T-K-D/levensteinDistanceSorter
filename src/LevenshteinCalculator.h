#ifndef LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H
#define LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <iomanip>
using namespace std;
class LevenshteinCalculator {

public:
    LevenshteinCalculator(string compareSource)
    : _compareSource(compareSource){}
    int compare(string obj) {
        //memoization
        if (compareResults.count(obj) > 0){
            return compareResults[obj];
        }
        int res;
        if (_compareSource.length() == 0){
            res = obj.length();
        } else if (obj.length() == 0) {
            res = _compareSource.length();
        }else if (_compareSource == obj) {
            res = 0;
        }else {
            //res = compareRecursive(obj);
            //res = compareWagnerFischer(obj);
            res = compareWithTwoMatrixRows(obj);
        }
        compareResults[obj] = res;
        return res;

    };
private:
    string _compareSource;
    unordered_map<string,int> compareResults;
    size_t compareRecursive(string& obj);
    size_t compareWagnerFischer(string& obj);
    size_t compareWithTwoMatrixRows(string& obj);
};


#endif //LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

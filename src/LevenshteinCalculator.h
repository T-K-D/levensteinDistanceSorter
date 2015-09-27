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
    size_t compare(const string& obj) {
        //memoization
        if (compareResults.count(obj) > 0){
            return compareResults[obj];
        }
        size_t res;
        if (_compareSource.length() == 0){
            res = obj.length();
        } else if (obj.length() == 0) {
            res = _compareSource.length();
        }else if (_compareSource == obj) {
            res = 0;
        }else {
            //res = compareRecursive(obj);
            //res = compareWagnerFischer(obj);
            //res = compareWithTwoMatrixRows(obj);
        }
        compareResults[obj] = res;
        return res;

    };
private:
    string _compareSource;
    unordered_map<string,int> compareResults;
    size_t compareRecursive(const string& obj);
    size_t compareWagnerFischer(const string& obj);
    size_t compareWithTwoMatrixRows(const string& obj);
};


#endif //LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

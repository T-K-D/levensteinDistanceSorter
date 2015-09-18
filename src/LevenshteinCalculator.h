#ifndef LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H
#define LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

#include <string>
#include <unordered_map>
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

        if (_compareSource.length() == 0) return obj.length();
        if (obj.length() == 0) return _compareSource.length();
        if (_compareSource == obj) return 0;

        //int res = compareRecursive(obj);
        int res = compareWagnerFischer(obj);
        //int res = compareWithTwoMatrixRows(obj);

        compareResults[obj] = res;
        return res;

    };
private:
    string _compareSource;
    unordered_map<string,int> compareResults;
    int compareRecursive(string& obj);
    int compareWagnerFischer(string& obj);
    int compareWithTwoMatrixRows(string& obj);
};


#endif //LEVENSTEINDISTANCESORTER_LEVENSHTEINCALCULATOR_H

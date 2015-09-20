#include <algorithm>
#include <fstream>
#include "LevenshteinSorter.h"
#include <iostream>

vector<string> LevenshteinSorter::sortVector(vector<string> base) {
    sort(base.begin(),base.end(),
         [&] (string x, string y) {
             return calculator.compare(x) > calculator.compare(y);
         });
    return base;
}

vector<string> getFileContents(string filename) {
    ifstream f (filename);
    vector<string> res;
    string line;
    while (getline(f,line)){
        res.push_back(line);
    }
    return res;
}

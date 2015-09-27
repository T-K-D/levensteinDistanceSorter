#include <algorithm>
#include <fstream>
#include "LevenshteinSorter.h"

void LevenshteinSorter::sortVector(vector<string>& base) {
    sort(base.begin(),base.end(),
         [&] (const string& x,const string& y) {
             return calculator.compare(x) < calculator.compare(y);
         });
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

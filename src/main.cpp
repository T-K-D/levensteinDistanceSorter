#include <iostream>
#include <fstream>
#include "LevenshteinSorter.h"
using namespace std;

#include <chrono>

int main(){
    vector<string> lines = getFileContents("/home/dasd/Dropbox/IV/I/ca_2/levensteinDistanceSorter/strings.gen");
    LevenshteinSorter sorter = LevenshteinSorter(lines[0]);
    cout << "opened file\n";
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sorter.sortVector(lines);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "t:" <<  chrono::duration_cast<chrono::microseconds>(end - begin).count() / (1e6);
    ofstream stats;
    stats.open("/home/dasd/stats.txt", ios_base::app);
    stats << "t:" <<  chrono::duration_cast<chrono::microseconds>(end - begin).count() / (1e6);
    return 0;
}
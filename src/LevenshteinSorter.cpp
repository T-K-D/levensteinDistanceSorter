#include <algorithm>
#include "LevenshteinSorter.h"

vector<string> LevenshteinSorter::sortStr(vector<string> base) {
    sort(base.begin(),base.end(),
         [&] (string x, string y) {
             return calculator.compare(x) > calculator.compare(y);
         });
    return base;
}

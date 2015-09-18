#include <algorithm>
#include "LevenshteinSorter.h"

vector<string> LevenshteinSorter::sort(vector<string> base) {
    sort(base.begin(),base.end(),
         [&calculator] (string x, string y) {
             return calculator.compare(x) > calculator.compare(y);
         });
    return base;
}

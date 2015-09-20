#include "LevenshteinCalculator.h"
#include <vector>
#include <algorithm>
size_t levHelper(string &s, int len_s, string &t, int len_t){
    if (len_s == 0) return len_t;
    if (len_t == 0) return len_s;
    int cost = (s[len_s-1] == t[len_t-1]) ? 0 : 1;

    return min({levHelper(s,len_s - 1, t, len_t    ) + 1,
               levHelper(s,len_s    , t, len_t - 1) + 1,
               levHelper(s,len_s - 1, t, len_t - 1) + cost});
};
//recursive algorithm (from definition)
size_t LevenshteinCalculator::compareRecursive(string& obj) {
    return levHelper(_compareSource, _compareSource.length(), obj, obj.length());
}


//Wagner-Fischer algorithm
size_t LevenshteinCalculator::compareWagnerFischer(string& obj){
    //init matrix of size [compareSource.length() + 1][obj.length() + 1]
    const unsigned long m = _compareSource.length() + 1;
    const unsigned long n = obj.length() + 1;
    vector<vector<size_t >> matrix(m,vector<size_t >(n));

    for(size_t i = 0; i < m; i++) matrix[i][0] = i;
    for(size_t j = 0; j < n; j++) matrix[0][j] = j;

    //calculate distaces
    for(size_t j = 1; j < n; j++){
        for(size_t i = 1; i < m; i++){
            if (_compareSource[i - 1] == obj[j - 1]){
                matrix[i][j] = matrix[i-1][j-1];
            }else{
                matrix[i][j] = min({matrix[i-1][j]   + 1,
                                   matrix[i]  [j-1] + 1,
                                   matrix[i-1][j-1] + 1});
            }
        }
    }

    return matrix[m - 1][n - 1];
}

size_t LevenshteinCalculator::compareWithTwoMatrixRows(string& obj) {
    vector<size_t > firstRow = vector<size_t >(obj.length() + 1);
    vector<size_t > secondRow= vector<size_t >(obj.length() + 1);
    for(size_t i = 0; i < obj.length() + 1; i++){
        secondRow[i] = i;
    }

    for (size_t i = 0; i < _compareSource.length(); i++){
        firstRow[0] = i + 1;
        for(int j = 0; j < obj.length(); j++){
            int cost = (_compareSource[i] == obj[j]) ? 0 : 1;
            firstRow[j + 1] = min({firstRow[j] + 1, secondRow[j + 1] + 1, secondRow[j] + cost});
        }
        firstRow.swap(secondRow);
    }

    return secondRow[obj.length()];
}

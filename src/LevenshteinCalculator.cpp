#include "LevenshteinCalculator.h"
#include <vector>
#include <functional>

int min3(int a, int b, int c){
    return min(min(a,b),min(b,c));
}

//recursive algorithm (from definition)
int LevenshteinCalculator::compareRecursive(string& obj) {
    std::function<int(string&,int,string&,int)> levHelper = [&levHelper](string &s, int len_s, string &t, int len_t){
        if (len_s == 0) return len_t;
        if (len_t == 0) return len_s;
        int cost = (s[len_s-1] == t[len_t-1]) ? 0 : 1;

        return min3(levHelper(s,len_s - 1, t, len_t    ) + 1,
                    levHelper(s,len_s    , t, len_t - 1) + 1,
                    levHelper(s,len_s - 1, t, len_t - 1) + cost);
    };
    return levHelper(_compareSource, _compareSource.length(), obj, obj.length());
}


//Wagner-Fischer algorithm
int LevenshteinCalculator::compareWagnerFischer(string& obj){
    //init matrix of size [compareSource.length() + 1][obj.length() + 1]
    const unsigned long m = _compareSource.length() + 1;
    const unsigned long n = obj.length() + 1;
    vector<vector<int>> matrix(m);

    for(int i = 0; i < m; i++){
        matrix[i] = vector<int>(n);
        for(int j = 1; j < n; j++){
            matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++) matrix[i][0] = i;
    for(int j = 0; j < n; j++) matrix[0][j] = j;

    //calculate distaces
    for(int j = 1; j < n; j++){
        for(int i = 1; i < m; i++){
            if (_compareSource[i - 1] == obj[j - 1]){
                matrix[i][j] = matrix[i-1][j-1];
            }else{
                matrix[i][j] = min3(matrix[i-1][j]   + 1,
                                    matrix[i]  [j-1] + 1,
                                    matrix[i-1][j-1] + 1);
            }
        }
    }

    return matrix[m - 1][n - 1];
}

int LevenshteinCalculator::compareWithTwoMatrixRows(string& obj) {
    vector<int> firstRow = vector<int>(obj.length() + 1);
    vector<int> secondRow= vector<int>(obj.length() + 1);
    for(int i = 0; i < obj.length() ; i++){
        firstRow[i] = i;
        secondRow[i] = 0;
    }

    for (int i = 0; i < _compareSource.length(); i++){
        secondRow[0] = i + 1;
        for(int j = 0; j < obj.length(); j++){
            int cost = (_compareSource[i] == obj[j]) ? 0 : 1;
            secondRow[j + 1] = min3(secondRow[j] + 1, firstRow[j + 1] + 1, firstRow[j] + cost);
        }

        for(int j = 0; j < obj.length() + 1; j++){
            firstRow[j] = secondRow[j];
        }
    }

    return secondRow[obj.length()];
}

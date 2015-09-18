#include "LevenshteinCalculator.h"
#include <vector>

int min3(int a, int b, int c){
    return min(min(a,b),min(b,c));
}

int LevenshteinCalculator::compare(std::string obj) {
    //memoization
    if (compareResults.count(obj) > 0){
        return compareResults[obj];
    }
    //actual calculation

    //init matrix of size [compareSource.length() + 1][obj.length() + 1]
    const unsigned long m = _compareSource.length() + 1;
    const unsigned long n = obj.length() + 1;
    vector<vector<int>> matrix(m);

    for(int i = 0; i < m; i++){
        matrix[i] = vector<int>(n);
        //matrix[i][0] = i;
        for(int j = 1; j < n; j++){
            matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++) matrix[i][0] = i;
    for(int j = 0; j < n; j++) matrix[0][j] = j;

    for(int j = 1; j < n; j++){
        for(int i = 1; i < m; i++){
            if (_compareSource[i - 1] == obj[j - 1]){
                matrix[i][j] = matrix[i-1][j-1];
            }else{
                matrix[i][j] = min3(matrix[i-1][j] + 1,
                                    matrix[i][j-1] + 1,
                                    matrix[i-1][j-1] + 1);
            }
        }
    }

    return matrix[m - 1][n - 1];
}

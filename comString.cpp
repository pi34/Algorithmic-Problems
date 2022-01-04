#include <iostream>
#include <string.h>

using namespace std;

int main () {

    string first;
    string second;

    cin >> first;
    cin >> second;

    int n = first.size();
    int m = second.size();

    int matrix[n][m];

    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < m; ++l) {
            if (first[k] == second[l]) {
                matrix[k][l] = 1;
            } else {
                matrix[k][l] = 0;
            }

        };
    };

    int currVal = 0;
    int currI;
    int currJ;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = matrix[i][j] + matrix[i-1][j-1];
                if (matrix[i][j] > currVal) {
                    currVal = matrix[i][j];
                    currI = i;
                    currJ = j;
                };
            }
        };
    };

    cout << currVal << endl;
    cout << first.substr(currI-currVal+1, currVal) << endl;

}

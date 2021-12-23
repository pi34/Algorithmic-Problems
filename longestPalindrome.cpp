#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int main () 
{

    int specs[2];
    for (int i = 0; i <= 1; ++i) cin >> specs[i];

    int n = specs[0]
    
    int a[n];
    for (int i = 0; i < n-1; ++i) cin >> a[i];

    int matrix[n];

    for (int i = 0; i < n-1; ++i) {
        int row[n];
        for (int j = 0; j < n-1; ++j) {
            row[j] = 0
            if (i == j) {
                row[j] = 1
            }
            if (j-i == 1) {
                if (a[i] == a[j]) {
                    row[j] = 1
                }
            }
        }
        matrix[i] = row
    }

    int longest = 0;
    int indiceS;
    int indiceE;

    for (k = 0; k < n-1; ++k) {
        for (q = k; q < n-1; ++q) {
            if (a[k] == a[q]) {
                if (matrix[k+1][q-1] == 1) {
                    matrix[k][q] = 1
                    if (q-k+1 > longest) {
                        longest = q-k+1
                        indiceS = k
                        indiceE = q
                    }
                }
            }
        }
    }

}

#include <iostream>
#include <limits>
#include <vectors>

using namespace std;

int main () 
{
    int n;
    cin >> n;

    int matrix[n][n];
    int tot = 0;
    int ySum[n];
    int xSum[n];

    for (int i = 0; i < n; ++i) {
        currSum = 0;
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            tot = tot + matrix[i][j];
            currSum = currSum + matrix[i][j];
            ySum[j] = ySum[j-1] + matrix[i][j];
        };
        if (i == 0) {
            xSum[i] = currSum;
        } else {
            xSum[i] = xSum[i-1] + currSum;
        };
    };

    int topLeft[n][n];
    int topRight[n][n];
    int bottomLeft[n][n];
    int bottomRight[n][n];

    int minima = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            topLeft[i][j] = matrix[i][j] +  topLeft[i-1][j] + topLeft[i][j-1] - topLeft [i-1][j-1];
            topRight[i][j] = xSum[i] - topLeft[i][j];
            bottomLeft[i][j] = ySum[j] - topLeft[i][j];
            bottomRight[i][j] = tot - (topRight[i][j] + bottomLeft[i][j] + topLeft[i][j]);
            topLeftArea = (i+1) * (j+1);
            topRightArea = (n-j) * (i+1);
            bottomLeftArea = (n-i) * (j+1);
            bottomRightArea = (n-j) * (n-i);

            if (topLeftArea < topRightArea && topLeftArea < bottomLeftArea && topLeftArea < bottomRightArea) {
                if (topLeft > minima) {
                    minima = topLeft;
                };
            } else if (topRightArea < topLeftArea && topRightArea < bottomLeftArea && topRightArea < bottomRightArea) {
                if (topRight > minima) {
                    minima = topRight;
                };
            } else if (bottomLeftArea < topLeftArea && bottomLeftArea < topRightArea && bottomLeftArea < bottomRightArea) {
                if (bottomLeft > minima) {
                    minima = bottomLeft;
                };
            } else if (bottomRightArea < topLeftArea && bottomRightArea < topRightArea && bottomRightArea < bottomLeftArea) {
                if (bottomRight > minima) {
                    minima = bottomRight;
                };
            }
        }
    }

    cout << minima;

}

// Solution to this: https://www.iarcs.org.in/inoi/contests/feb2006/Advanced-2.php

#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int A1[n];
    int A2[n];

    for (int i = 0; i < n; ++i) {
        cin >> A1[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> A2[i];
    }

    int dp[n][n][3];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j][0] = 1;
            dp[i][j][1] = -1;
            dp[i][j][2] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < k; ++l) {
                    if ((A1[i]-A1[j] == A2[k]-A2[l]) && (dp[j][l][0] + 1 > dp[i][k][0])) {
                        dp[i][k][0] = dp[j][l][0] + 1;
                        dp[i][k][1] = j;
                        dp[i][k][2] = l;
                    };
                };
            };
        };
    };

    int max = 0;
    int x = -1;
    int y = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (max < dp[i][j][0]) {
                max = dp[i][j][0];
                x = i;
                y = j;
            }
        }
    }

    vector<int> finArr1;
    vector<int> finArr2;

    while ( x >= 0 || y >= 0 ) {
        finArr1.push_back(A1[x]);
        finArr2.push_back(A2[y]);
        int nx = dp[x][y][1];
        int ny = dp[x][y][2];
        x = nx;
        y = ny;
    }

    cout << max << endl;

    for (int i = finArr1.size()-1; i >= 0; i--) {
        cout << finArr1[i] << " ";
    }

    cout << endl;

    for (int i = finArr2.size()-1; i >= 0; i--) {
        cout << finArr2[i] << " ";
    }

    cout << endl;

}

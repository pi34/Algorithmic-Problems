
// Solution to this: https://www.codechef.com/problems/KGP14B

#include <iostream>
#include <string.h>

using namespace std;

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;

        string str1, str2;
        cin >> str1 >> str2;

        int dp[n+1][m+1];

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            };
        };

        int maxel = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                };
                maxel = max(maxel, dp[i][j]);
            };
        };
        
        cout << "Case "<< i+1 << ": " << maxel + (n-maxel) + (m-maxel) << endl;
    };
}

#include <iostream>

using namespace std;

const int tot = 45001;

int main ()
{
    int n;
    cin >> n;

    int values[n];
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        values[i] = abs(x-y);
    }

    bool dp[n+1][tot];
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= tot; j++) {
            dp[i][j] = (dp[i-1][abs(j-values[i-1])] || dp[i-1][abs(j+values[i-1])]);
        }
    }

}


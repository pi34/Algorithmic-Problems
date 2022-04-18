#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int dp[n+1][k+1];
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        int sums[k+1];
        sums[0] = dp[i-1][0];
        for (int j = 1; j <= k; j++) {
            sums[j] = sums[j-1] + dp[i-1][j];
        }

        for (int j = 0; j <= k; j++) {
            dp[i][j] = sums[j];
            if (j > arr[i]) {
                dp[i][j] -= sums[j-arr[i]-1];
            } 
        }
    }

    cout << dp[n][k] << "\n";
}

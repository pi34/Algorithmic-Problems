#include <iostream>
#include <vector>

using namespace std;

int n;

int arr[100002];
int dp[100002][3];

int dpp(int i, int st) {
    if (i > n) {
        return 0;
    }
    if (dp[i][st] != -1) {
        return dp[i][st];
    }
    if (i == n) {
        dp[i][st] = 1;
    }
    else if (st == 1 && arr[i] < arr[i+1]) {
        dp[i][st] = 1;
    }
    else if (st == 2 && arr[i] > arr[i+1]) {
        dp[i][st] = 1;
    }
    else if (st == 1 && arr[i] >= arr[i+1]) {
        dp[i][st] = 1 + dpp(i+1, 2);
    }
    else if (st == 2 && arr[i] <= arr[i+1]) {
        dp[i][st] = 1 + dpp(i+1, 1);
    }
    return dp[i][st];
}

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        int arr[n];
        for (int i = 1; i <= n; i++) cin >> arr[i];

        memset(dp, -1, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            dpp(i, 1);
            dpp(i, 2);
        }

        int fin = -1;

        for (int i = 1; i <= n; i++) {
            int x = dp[i][2];
            if (i+x > n) {
                fin = max(fin, dp[i][2]+1);
            } else if (i%2 == 0) {
                fin = max(fin, dp[i][2] + 1 + dp[i+x][1]);
            } else {
                fin = max(fin, dp[i][2] + 1 + dp[i+x][2]);
            }
        }

        cout << fin << "\n";
    }
}

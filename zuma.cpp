#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 505;

int arr[N];
int dp[N][N];

int dpp (int l, int r) {

    if (l == r) {
        return 1;
    }
    if (l > r) {
        return 0;
    }
    if (dp[l][r] != INF) return dp[l][r];
    dp[l][r] = min(dp[l][r], dpp(l+1, r)+1);

    for (int i = l + 2; i <= r; i++) {
        if (arr[l] == arr[i]) {
            dp[l][r] = min(dp[l][r], dpp(l+1, i-1)+dpp(i+1, r));
        }
    }

    if (arr[l] == arr[l+1]) {
        dp[l][r] = min(dp[l][r], dpp(l+2, r)+1);
    }
    return dp[l][r];
}

int main ()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];

    memset(dp, INF, sizeof(dp));

    cout << dpp(1, n) << "\n";
}

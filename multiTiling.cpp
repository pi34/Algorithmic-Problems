#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll N = 1e6;
const ll MOD = 1e9+7;

int main ()
{
    vector<vector<ll>> dp(N+1, vector<ll> (2));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (ll i = 2; i <= N; i++) {
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % MOD;
    }

    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }
}

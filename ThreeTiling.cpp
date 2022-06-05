#include <iostream>
#include

using namespace std;

using ll = long long;

ll M = 1e9+7;
ll N = 1e6+5;

int main ()
{
    ll t;
    cin >> t;
    
    ll dp[N];
    ll dp2[N];
    ll dp3[N];

    dp[1] = 1;
    dp2[1] = 0;
    dp3[1] = 0;

    dp[2] = 1;
    dp2[2] = 0;
    dp3[2] = 0;

    dp[3] = 2;
    dp2[3] = 0;
    dp3[3] = 1;

    for (ll i = 4; i < N; i++) {
        dp[i] = (dp[i-3] + dp[i-1] + 2 * dp2[i-2]) % M;
        dp2[i] = (dp3[i-1] + dp2[i-3]) % M;
        dp3[i] = (dp[i-3] + dp3[i-3]) % M;
    };

    while (t--) {
        ll k, n;
        cin >> k >> n;

        if (k == 1) {

            if (n % 3 == 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            };

        } else if (k == 2) {

            ll DP[n];

            DP[0] = 1;
            DP[1] = 0;
            DP[2] = 1;
            DP[3] = 1;

            for (ll i = 4; i <= n; ++i) {
                DP[i] = (DP[i-2] + DP[i-3]) % M;
            };

            cout << DP[n] << endl;

        } else if (k == 3) {

            cout << dp[n] << endl;

        }
    }
}

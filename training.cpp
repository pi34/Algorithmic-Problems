#include <iostream>

using namespace std;

typedef long long ll;

int main () {
    
    ll N, S;
    cin >> N >> S;

    ll E[N];

    for (int i = 0; i < N; ++i) {
        cin >> E[i];
    };

    ll s[N];
    s[0] = S;

    for (int i = 1; i < N; ++i) {
        ll curr = s[i-1];
        ll sum = 0;
        while (curr ) {
            sum = sum + (curr%10);
            curr = curr / 10;
        }
        s[i] = s[i-1] + (sum * sum * sum);
    }

    for (int i = 0; i < N; ++i) {
        cout << s[i] << endl;
    }

    ll dp[N][N];

    ll largest = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = E[0] * s[0];

    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i-1][0]+ E[i]*s[0];
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]+ E[i]*s[j]);
            largest = max(largest, dp[i][j]);
        }
    }

    cout << largest << endl;

}

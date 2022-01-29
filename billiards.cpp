#include <iostream>

using namespace std;

int main ()
{
    int N = 1000001;
    
    int dp[N];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= N; ++i) {
        dp[i] = (dp[i-3] + dp[i-2]) % 1000000009;
    }
    
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {

        int n;
        cin >> n;
        cout << dp[n] % 1000000009 << endl;

    }
}

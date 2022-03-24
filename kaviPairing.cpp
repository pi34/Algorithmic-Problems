#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int dp[n+1];
    dp[0] = 1;
    int sum = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i+i; j<= n; j+=i) {
            dp[j]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = sum + dp[i];
        sum = sum + dp[i];
    }

    cout << dp[n] << "\n";
}

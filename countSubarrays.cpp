#include <iostream>

using namespace std;

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int A[n];

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        int dp[n];

        for (int i = 0; i < n; ++i) {
            dp[i] = 0;
        }

        int sum = 0;

        int curr = 1;

        for (int i = 1; i < n; ++i) {
            if (A[i] >= A[i-1]) {
                curr++;
            } else {
                sum = sum + (((curr+1)*curr) / 2);
                curr = 1;
            }
        };

        sum = sum + (((curr+1)*curr) / 2);

        cout << dp[n-1] << endl;
    }
}

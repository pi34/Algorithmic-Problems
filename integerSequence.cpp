#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int dp1[n];

    for (int i = 0; i < n; i++) dp1[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp1[i] = max(dp1[j]+1, dp1[i]);
            }
        }
    }

    int dp2[n];

    for (int i = 0; i < n; i++) dp2[i] = 1;

    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j > i; j--) {
            if (arr[i] > arr[j]) {
                dp2[i] = max(dp2[j]+1, dp2[i]);
            }
        }
    }

    int maxim = 0;

    for (int i = 0; i < n; i++) {
        maxim = max(maxim, dp1[i]+dp2[i]-1);
    }

    cout << n - maxim << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lisdp (vector<pair<int, int>> matr, int ind, int n, int k) 
{
    int dp[n];

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(matr[i].second - matr[j].second) >= ind) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if (dp[i] >= k) {
            return 1;
        }
    }

    return 0;

}

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(make_pair(x, i+1));
        }

        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        int left = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (arr[i].first == arr[j].first) {
                    left = max(left, abs(arr[i].second-arr[j].second));
                }
            }
        }

        int right = n - 1;

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (lisdp(arr, mid, n, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        cout << left << endl;
    }
}

// https://dunjudge.me/analysis/problems/1811/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    vector<pair<int, int>> fc (n);

    for (int i = 0; i < n; ++i) {
        cin >> fc[i].first >> fc[i].second;
    }

    for (int i = 0; i < fc.size(); ++i) {
        cout << fc[i].first << " " << fc[i].second << endl;
    }

    sort(fc.begin(), fc.end());

    vector<int> dp(n, 0);

    dp[0] = fc[0].second;

    int fuse = fc[0].first;
    int maxim = -2;
    int pos = -1;

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i-1] + fc[i].second - (i*(abs(fc[i].first-fuse)));
        fuse = fc[i].first;
        if (maxim <= dp[i]) {
            maxim = dp[i];
            pos = i;
        }
    }

    for (int i = 0; i <= pos; ++i) {
        int curr = fc[i].second - fc[pos].first + fc[i].first;
        if (curr < 0) {
            maxim = maxim + abs(curr);
        }
    }

    cout << maxim << "\n";

}

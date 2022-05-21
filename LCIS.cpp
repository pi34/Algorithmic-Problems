// https://codeforces.com/contest/10/problem/D

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int M;

int dp[551][551], path[551][551], arr1[551], arr2[511];

bool print (int x) {
    if (!x) {
        return false;
    }
    if (print(path[N][x])) {
        cout << arr2[x] << " ";
    } else {
        cout << arr2[x] << " ";
    }
    return true;
}

int main ()
{
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> arr1[i];

    cin >> M;

    for (int i = 1; i <= M; i++) cin >> arr2[i];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++) {
        int count = 0;
        int posit = 0;
        for (int j = 1; j <= M; j++) {

        dp[i][j] = dp[i-1][j];
        path[i][j] = path[i-1][j];
            if (arr1[i] == arr2[j] && count+1 > dp[i][j]) {
                dp[i][j] = count+1;
                path[i][j] = posit;
            }
            if (arr1[i] > arr2[j] && dp[i-1][j]>count) {
                count = dp[i-1][j];
                posit = j;
            }
        }
    }

    int fin = 1;

    for (int i = 1; i <= M; i++) {
        if (dp[N][i] > dp[N][fin]) {
            fin = i;
        }
    }

    cout << dp[N][fin] << "\n";

    if (dp[N][fin]) {
        print(fin);
        cout << "\n";
    }

}

// https://cses.fi/problemset/task/1158

#include <iostream>

using namespace std;

int main ()
{
    int n, x;
    cin >> n >> x;

    int prices[n];
    int pages[n];

    for (int i = 1; i <= n; ++i) cin >> prices[i];
    for (int j = 1; j <= n; ++j) cin >> pages[j];

    int matr[n+1][x+1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            matr[i][j] = -20;
        }
    }

    for (int i = 0; i <= x; ++i) {
        matr[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            matr[i][j] = matr[i-1][j];
            if (j >= prices[i]) {
                matr[i][j] = max(matr[i][j], matr[i-1][j-prices[i]]+pages[i]);
            }
        }
    }

    cout << matr[n][x] << "\n";
}

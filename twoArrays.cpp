#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;

    int matr[n+1][m+1];

    vector<vector<bool>> seen(n+1, vector <bool> (10e9+1, false));

    int w[n+1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matr[i][j];
            if (!seen[i][matr[i][j]]) {
                seen[i][matr[i][j]] = true;
            }
        }
        cin >> w[i];
    }

    int  minima = INT_MAX;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            bool found = false;
            for (int k = 1; k <= m; k++) {
                if (seen[j][matr[i][k]]) {
                    found = true;
                    break;
                }
            }
            if (!found) minima = min(minima, w[i]+w[j]);
        }
    }

    if (minima != INT_MAX) cout << minima << "\n";
    else cout << -1 << "\n";

}

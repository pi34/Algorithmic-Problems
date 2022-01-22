// Solution to this: https://www.iarcs.org.in/inoi/contests/apr2005/Advanced-2.php

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main ()
{
    int n; 
    cin >> n;

    ll adjList[n+1][n+1];

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            adjList[i][j] = 0;
        }
    }

    for (ll i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        for (ll j = 1; j <= m; ++j) {
            int x;
            cin >> x;
            adjList[i][x] = 1;
            
        }
    }

    ll arr[2005];

    if (adjList[1][2] == 1) {
        arr[1] = 1;
        arr[2] = 2;
    } else {
        arr[1] = 2;
        arr[2] = 1;
    }

    for (ll k = 2; k < n; k++) {
        ll j = k + 1;
        if (adjList[j][arr[1]] == 1) {
            for (ll i = j; i >= 2; i--) {
                arr[i] = arr[i-1];
            };
            arr[1] = j;
        } else if (adjList[k][j] == 1) {
            arr[j] = j;
        } else {
            for (ll i = 1; i <= k; ++i) {
                if (adjList[j][i] == 1) {
                    for (ll l = j; l > i; l--) {
                        arr[l] = arr[l-1];
                    }
                    arr[i] = j;
                    break;
                };
            };
        };
    };

    cout << "YES" << endl;

    for (ll i = 1; i <= n; ++i) {
        cout << arr[i] << " ";
    }
}

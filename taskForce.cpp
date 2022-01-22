// Solution to this: https://www.iarcs.org.in/inoi/contests/mar2005/Advanced-2.php

#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main ()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> adjList[n];
    ll number[n]; 

    for (ll i = 0; i < n; ++i) {
        number[i] = 0;
    }

    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        x = x - 1;
        y = y - 1;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        number[x] = number[x] + 1;
        number[y] = number[y] + 1;
    }

    queue <ll> que;
    bool queued[n];
    bool deleted[n];

    for (ll i = 0; i < n; ++i) {
        queued[i] = false;
        deleted[i] = false;
        if (number[i] < k) {
            que.push(i);
            queued[i] = true;
        }
    }

    while (!que.empty()) {

        ll node = que.front();
        que.pop();

        queued[node] = false;
        deleted[node] = true;

        for (auto i: adjList[node]) {
            if (!queued[i] && !deleted[i]) {
                number[i] = number[i] - 1;
                if (number[i] < k) {
                    que.push(i);
                    queued[i] = true;
                }
            }
        }

    }

    ll count = 0;

    for (ll i = 0; i < n; ++i) {
        if (!deleted[i]) {
            count++;
        };
    };

    if (count > 0) {
        cout << "YES" << endl;
        cout << count << endl;
    } else {
        cout << "NO" << endl;
    }

}

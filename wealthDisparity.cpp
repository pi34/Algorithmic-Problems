#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

vector<vector<ll>> adjList;
vector<bool> visited;

ll ans = -1000000;

void dfs (ll node, ll man, ll A[])
{
    visited[node] = true;
    man = max(man, A[node]);

    for(auto i: adjList[node]) {
        if (visited[i] == false) {
            ans = max(ans, man-A[i]);
            dfs(i, man, A);
        };
    };
}

int main ()
{
    ll n;
    cin >> n;

    ll A[n];
    ll P[n];

    ll hojo;

    adjList.resize(n);
    visited.resize(n, false);

    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (ll i = 0; i < n; ++i) {
        int par;
        cin >> par;
        par--;
        if (par == -2) {
            hojo = i;
        } else {
            adjList[par].push_back(i);
            P[i] = par;
        }
    }

    visited[hojo] = true;

    dfs(hojo, A[hojo], A);

    cout << ans << endl;

}

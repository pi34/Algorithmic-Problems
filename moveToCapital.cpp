// https://codeforces.com/contest/1472/problem/G

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100001;

vector<vector<int>> adjList (N);
vector<int> finDist (N, -1);
vector<int> dp (N);
vector<bool> visited (N, false);

void bfs () {
    finDist[1] = 0;
    queue<int> que;
    que.push(1);

    while (!que.empty()) {
        int curr = que.front();
        que.pop();
        for (int i: adjList[curr]) {
            if (finDist[i] == -1) {
                finDist[i] = finDist[curr] + 1;
                que.push(i);
            }
        }
    }
}

void dfs (int node) {
    visited[node] = true;
    dp[node] = finDist[node];
    for (int i: adjList[node]) {
        if (!visited[i] && finDist[node] < finDist[i]) {
            dfs(i);
        }

        if (finDist[node] < finDist[i]) {
            dp[node] = min(dp[node], dp[i]);
        } else {
            dp[node] = min(dp[node], finDist[i]);
        }
    }
}

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            adjList[i].clear();
            finDist[i] = -1;
            dp[i] = 0;
            visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;

            adjList[x].push_back(y);
        }

        bfs();

        dfs(1);

        for (int i = 1; i <= n; i++) cout << dp[i] << " ";
        cout << "\n";

    }
}

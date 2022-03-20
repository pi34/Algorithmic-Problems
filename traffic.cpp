#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<int> adjList[n+1];

    int grid[n+1][n+1];
    memset(grid, false, sizeof(grid));

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        grid[x][y] = true;
    }

    bool visited[n+1];
    int dist[n+1];

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }

    queue<int> que;
    que.push(s);
    visited[s] = true;

    while (!que.empty()) {
        int node = que.front();
        que.pop();

        for (auto i: adjList[node]) {
            if (!visited[i]) {
                visited[i] = true;
                dist[i] = dist[node] + 1;
                que.push(i);
            }
        }

    }

    bool visited2[n+1];
    int dist2[n+1];

    for (int i = 1; i <= n; i++) {
        visited2[i] = false;
        dist2[i] = 0;
    }

    queue<int> que2;
    que2.push(t);
    visited2[t] = true;

    while (!que2.empty()) {
        int node = que2.front();
        que2.pop();

        for (auto i: adjList[node]) {
            if (!visited2[i]) {
                visited2[i] = true;
                dist2[i] = dist2[node] + 1;
                que2.push(i);
            }
        }

    }

    int D = dist[t];
    int tot = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (!grid[i][j]) {
                if ((dist[i] + dist2[j] + 1 >= D) && (dist[j] + dist2[i] + 1 >= D)) tot++;
            }
        }
    }

    cout << tot << "\n";

}

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

void dfs(int node, int forbidden) {
    visited[node] = true;
    for (auto i: adjList[node]) {
        if (!visited[i]) {
            if (i == forbidden) continue;
            dfs(i, forbidden);
        }
    }
}

int main ()
{
    int n, m;
    cin >> n >> m;

    adjList = vector<vector<int>>(n+1);

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].emplace_back(y);
        adjList[y].emplace_back(x);
    }

    vector<int> ansFin;

    for (int i = 1; i <= n; i++) {
        visited = vector<bool> (n+1, false);
        int forbid = 1;
        if (i == 1) forbid = 2;
        dfs(forbid, i);
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (!visited[j]) {
                ansFin.push_back(i);
                break;
            }
        }
    }

    cout << ansFin.size() << "\n";
    for (auto i: ansFin) cout << i << " ";
    cout << "\n";

}

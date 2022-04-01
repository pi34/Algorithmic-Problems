#include <iostream>
#include <vector>

using namespace std;

const int N = 1000;

int state[N];
vector<int> fin;
vector <int> adjList[N];

int childArr[N];

int dp[N];

void topSort (int node)
{
    if (state[node] == 1 || state[node] == 2) return;
    state[node] = 1;

    for (auto i: adjList[node]) {
        topSort(i);
    }

    state[node] = 2;
    fin.push_back(node);
}

void dfs (int node)
{
    for (auto i: adjList[node]) {
        dp[node] = max(dp[i]+1, dp[node]);
        if (dp[node] == dp[i]+1) {
            childArr[node] = i;
        }
    }
}

int main ()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adjList[x].push_back(y);
    }

    for (int i = 0; i < n; i++) {
        state[i] = 0;
    }

    topSort(0);

    bool found = false;

    for (int i = 0; i < fin.size(); i++) {
        if (found) dfs(fin[i]);
        if (fin[i] == n-1) {
            found = true;
            dp[n-1] = 1;
        }
    }

    cout << dp[n-1] << endl;

    int i = 1;
    while (i != n-1) {
        cout << i << " ";
        i = childArr[i];
    }
}

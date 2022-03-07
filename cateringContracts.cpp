#include <iostream>
#include <vector>

using namespace std;

int arr[100005];
vector<int> adjList [100005];
bool visited [100005];

int dp[100005][2];

void dfs (int node) {
    visited[node] = true;
    dp[node][1] += arr[node];
    for (auto i: adjList[node]) {
        if (!visited[i]) {
            dfs(i);
            dp[node][1] += dp[i][0];
            dp[node][0] += max(dp[i][0], dp[i][1]);
        }
    }
}

int main ()
{
    int n;
    cin >> n;

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
        cin >> arr[i]; 
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << endl;

}

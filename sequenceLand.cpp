#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 304;

vector<bool> visited;
vector<vector<int>> adjList;

int ans = 0;

void dfs (int node)
{
    visited[node] = true;
    ans++;

    for(auto i: adjList[node]) {
        if (visited[i] == false) {
            dfs(i);
        }
    }
}

int main () 
{

    int n, K;
    cin >> n >> K;

    adjList.resize(n);
    visited.resize(n, false);

    vector<int> ids [n];

    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;

        vector<int> curr;

        for (int k = 0; k < len; ++k) {
            int yes;
            cin >> yes;
            curr.push_back(yes);
        }

        sort(curr.begin(), curr.end());
        ids[i] = curr;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int ind1 = 0;
            int ind2 = 0;
            int com = 0;
            while (ind1 < ids[i].size() && ind2 < ids[j].size()) {
                if (ids[i][ind1] == ids[j][ind2]) {
                    com++;
                    ind1++;
                    ind2++;
                } else if (ids[i][ind1] > ids[j][ind2]) {
                    ind2++;
                } else {
                    ind1 ++;
                }
            }

            if (com >= K) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    dfs(0);

    cout << ans << endl;

}

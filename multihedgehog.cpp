// https://codeforces.com/contest/1068/problem/E

#include <iostream>
#include <vector>

using namespace std;

int n = 100002;

vector<vector<int>> adjList(n+1);
vector<int> degrees(n+1);
vector<int> sizes(n+1);
vector<int> preCum(n+1);
vector<int> depths(n+1);

int mxdepth;
int dex;

void dfs (int node, int maxdep, int par) {
    depths[node] = maxdep;
    if (maxdep > mxdepth) {
        mxdepth = maxdep;
        dex = node;
    }
    for (auto i: adjList[node]) {
        if (i == par) {
            continue;
        }
        sizes[node]++;
        preCum[i] = node;
        dfs(i, maxdep+1, node);
    }
}

int main () 
{
    int k;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        degrees[x]++;
        degrees[y]++;
    }

    int currRoot = 0;

    for (int i = 1; i <= n; i++) {
        if (degrees[i] == 1) {
            currRoot = i;
            break;
        }
    }

    dfs(currRoot, 1, 0);

    int mid = (mxdepth+1)>>1;

    while (depths[dex] != mid) {
        dex = preCum[dex];
    }

    currRoot = dex; 

    sizes.clear();
    sizes.resize(n+1, 0);
    depths.clear();
    depths.resize(n+1, 0);

    dfs(currRoot, 1, 0);

    bool is = true;

    for (int i = 1; i <= n; i++) {
        if (sizes[i] == 0) {
            if (depths[i] != k+1) {
                is = false;
                break;
            }
        } else {
            if (sizes[i] < 3) {
                is = false;
                break;
            }
        }
    }

    if (is) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

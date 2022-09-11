// https://codeforces.com/contest/500/problem/B

#include <iostream>
#include <vector>

using namespace std;

int n = 301;
vector< vector<int> > grid(n);
vector<int> perm (0, n);

vector<int> visited (0, n);

vector< vector<int> > comps;
vector<int> curr;


int dfs (int node) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (grid[node][i] == 1 && visited[i] != 1) {
            curr.push_back(i);
            dfs(i);
        }
    }
}

int main () {

    cin >> n;

    for (int i = 0; i < n; i++) cin >> perm[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            curr.clear();
            curr.push_back(i);
            dfs(i);
            comps.push_back(curr);
        }
    }

    int pritned[n];

    for (vector<int> comp: comps) {
        vector<int> tP;
        for (int ind: comp) {
            tP.push_back(perm[ind]);
        }
        sort(tP.begin(), tP.end());
        sort(comp.begin(), comp.end());

        for (int i = 0; i < comp.size(); i++) {
            pritned[comp[i]] = tP[i];
        }
    }

    for (int p: pritned) cout << p << " ";
    cout << "\n";

}

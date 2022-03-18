#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> removables;
bool maze[505][505];
bool visited[505][505];

int n, m;

void dfs (int x, int y) {
    if (maze[x][y]) {
        visited[x][y] = true;

        if (x+1 < n && !visited[x+1][y]) {
            dfs(x+1, y);
        }
        if (x - 1 >= 0 && !visited[x-1][y]) {
            dfs(x-1, y);
        }
        if (y+1 < m && !visited[x][y+1]) {
            dfs(x, y+1);
        }
        if (y - 1 >= 0 && !visited[x][y-1]) {
            dfs(x, y-1);
        }

        removables.push_back(make_pair(x, y));
    }
}

int main ()
{
    int k;
    cin >> n >> m >> k;

    string final[n][m];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            visited[i][j] = false;
        }
    }

    int firI = -1;
    int firJ = -1;
    bool found = false;

    for (int i = 0; i < n; i++) {
        string curr;
        cin >> curr;
        vector<char> v(curr.begin(), curr.end());
        for (int j = 0; j < m; j++) {
            if (v[j] == '.') {
                maze[i][j] = true;
                if (!found) {
                    firI = i;
                    firJ = j;
                    found = true;
                }
            }
            else maze[i][j] = false;
            final[i][j] = string(1, v[j]);
        }
    };

    dfs(firI, firJ);

    for (int i = 0; i < k; i++) {
        int x = removables[i].first;
        int y = removables[i].second;
        final[x][y] = "X";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << final[i][j];
        }
        cout << "\n";
    }


}

#include <iostream>

using namespace std;

int N = 502;
int visited[N][N];

queue<pair<int, pair<int, int>>> que

int main () {
    int t;
    cin >> t;

    while (t--) {

        int currM = -90;

        int n, m;
        cin >> n >> m;

        int a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                visited[i][j] = 0;
                currM = max(a[i][j], currM);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == currM) {
                    visited[i][j] = 1;
                    que.push(((i, j), 0));
                }
            }
        }

        int sol = 0;
        int i = 0;
        int j = 0;
        int dist = 0;

        while (!que.empty()) {
            i = que.front().second.first;
            j = que.front().second.second;
            visited[i][j] = 1;
            dist = que.front().first;

            que.pop();
            sol = max(sol, dist);

            if (i+1 < n && j+1 < m) {
                que.push(((i+1, j+1), dist+1))
            }
            if (i+1 < n && j-1 >= 0) {
                que.push(((i+1, j-1), dist+1))
            }
            if (i-1 >= 0 && j+1 < m) {
                que.push(((i-1, j+1), dist+1))
            }
            if (i-1 >= 0 && j-1 >= 0) {
                que.push(((i-1, j-1), dist+1))
            }
            if (i+1 < n) {
                que.push(((i+1, j), dist+1))
            }
            if (j+1 < m) {
                que.push(((i, j+1), dist+1))
            }
            if (i-1 >= 0) {
                que.push(((i-1, j), dist+1))
            }
            if (j-1 >= 0) {
                que.push(((i, j-1), dist+1))
            }
        }

        cout << sol << "\n";
    }
}

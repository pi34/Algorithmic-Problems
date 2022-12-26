#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main ()
{

    vector<vector<char>> matrix = {
                    {'M', 'S', 'E', 'F'},
                    {'R', 'A', 'T', 'D'},
                    {'L', 'O', 'N', 'E'}
                };
 
    unordered_set<string> a = { "START", "NOTE", "SAND", "STONED" };
    
    int n = matrix.size()
    int m = matrix[0].size()

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            DFS(i, k, "");
        }
    };

    unordered_set<string> result;

    void DFS (int i, int j, string curr, auto &result) {

        if (i<0 || j<0 || i>=n || j>=m) {
            return
        }

        marked.push_back([i, j])
        curr = curr + matrix[i][j]

        if (a.find(curr) != a.end()) {
            result.insert(curr);
        }

        DFS (i-1, j-1, curr)
        DFS (i-1, j, curr)
        DFS (i, j-1, curr)
        DFS (i+1, j+1, curr)
        DFS (i+1, j, curr)
        DFS (i, j+1, curr)
        DFS (i+1, j-1, curr)
        DFS (i-1, j+1, curr)

    }

    cout << result;

}

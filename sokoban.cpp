#include <iostream>

using namespace std;

int main ()
{
    int n, e;
    cin << n << e;

    int grid[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = 0
        }
    }

    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        grid[x-1][y-1] = 1
    }

    int sx, sy, bx, by, tx, ty;
    cin >> sx >> sy >> bx >> by >> tx >> ty;

    
    
}

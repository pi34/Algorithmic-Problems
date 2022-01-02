#include <iostream>
#include <vector>

using namespace std;

void dpf (int d, int currDI, int currDJ, int i, int j, int r, int c, vector < vector<int> > &grid, vector < vector<int> > &dp) {
    
    if ( (i == 0 && j == 1) || (i == 1 && j == 0) ) 
    {
        dp[i][j] = 1;
    }
    else if (i == 0 && j == 0)
    {
        dp[i][j] = 0;
    } 
    else 
    {
        if (i == 0) {
            dp[i][j] = dp[i][j-1];
        } else if (j == 0) {
            dp[i][j] = dp[i-1][j];
        } else {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    };

    if (i != r && j == c) {
        if (i+1 == r && j == c) 
        {
            return;
        };
        if (grid[i+1][j] != 0) {
            if (currDJ != d) {
                dpf(d, 0, currDJ+1, i+1, j, r, c, grid, dp);
            };
        };
    } else if (i == r && j != c) {
        if (i == r && j+1 == c) 
        {
            return;
        };
        if (grid[i][j+1] != 0) {
            if (currDI != d) {
                dpf(d, currDI+1, 0, i, j+1, r, c, grid, dp);
            };
        };
    } else {
        if (currDI != d) {
            if (i == r && j+1 == c) 
            {
                return;
            };
            if (j+1 != c) {
                if (grid[i][j+1] != 0) {
                    dpf(d, currDI+1, 0, i, j+1, r, c, grid, dp);
                };
            }
        };
        if (currDJ != d) {
            if (i+1 == r && j == c) 
            {
                return;
            };
            if (i+1 != r) {
                if (grid[i+1][j] != 0) {
                    dpf(d, 0, currDJ+1, i+1, j, r, c, grid, dp);
                };
            }
        };
    };

}

int main () {

    int r, c, d;
    cin >> r >> c >> d;

    vector <vector<int>> grid;
    vector <vector<int>> dp;

    for (int i = 0; i < r; ++i) {
        vector<int> currG;
        vector<int> currD;
        for (int j = 0; j < c; ++j) {
            int curr;
            cin >> curr;
            currG.push_back(curr);
            currD.push_back(0);
        };
        grid.push_back(currG);
        dp.push_back(currD);
    };


    dpf(d, 0, 0, 0, 0, r, c, grid, dp); 

    cout << dp[r-1][c-1] << endl; 

}

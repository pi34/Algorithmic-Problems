// Solution to this: https://www.iarcs.org.in/inoi/contests/aug2005/Advanced-2.php

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find (int ind, int set[]) 
{
    int c = set[ind];
    if (c == ind) {
        return ind;
    } else {
        set[ind] = find(c, set);
        return set[ind];
    };
};


int main ()
{
    int n;
    cin >> n;

    int matr[n][n];

    vector<pair<int, pair<int, int>>> pr;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cs;
            cin >> cs;
            if (i == j) {
                cs = 100001;
            }
            matr[i][j] = cs;
            pr.push_back(make_pair(cs, make_pair(i, j)));
        }
    }

    sort(pr.begin(), pr.end());

    int set[n];
    int size[n];

    for (int i = 0; i < n; ++i) {
        set[i] = i;
    }

    int weight = 0;

    for (int i = 0; i < n; ++i) {
        int x = pr[i].second.first;
        int y = pr[i].second.second;
        int cost = pr[i].first;
        if (x != 0 && y != 0) {
            int c1=find(x, set), c2=find(y, set);
            if (c1 != c2) {
                weight = weight + cost;
                set[c2] = c1;
            };
        };
    }

    cout << weight << endl;
}

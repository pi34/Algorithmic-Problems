// Solution to this: https://www.iarcs.org.in/inoi/contests/aug2005/Advanced-2.php

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector <int> set;

int find (int ind) 
{
    int c = set[ind];
    if (c == ind) {
        return ind;
    } else {
        set[ind] = find(c);
        return set[ind];
    };
};


int main ()
{
    int n;
    cin >> n;

    int matr[n][n];

    vector<pair<int, pair<int, int>>> pr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matr[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            pr.push_back(make_pair(matr[i][j], make_pair(i, j)));
        }
    }

    sort(pr.begin(), pr.end());

    set = vector<int> (n);

    for (int i = 0; i < n; ++i) {
        set[i] = i;
    }

    int weight = 0;

    for (pair<int, pair<int, int>> p:pr) {
        
        int x = p.second.first;
        int y = p.second.second;
        int cost = p.first;

        int c1=find(x), c2=find(y);
        if (c1 != c2) {
            weight = weight + cost;
            set[c2] = c1;
        };
    }

    cout << weight << endl;
}

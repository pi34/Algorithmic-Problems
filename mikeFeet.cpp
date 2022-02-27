// https://codeforces.com/problemset/problem/547/B

#include <iostream>
#include <vector>

using namespace std;

int N = 1000005;
vector<int> tot (N);
vector<int> sets (N);

int find (int node) {
    if (sets[node] == node) return node;
    else return sets[node] = find(sets[node]);
}

void merge (int u, int v) {
    int su = find(u);
    int sv = find(v);
    if (su == sv) return;
    sets[sv] = su;
    tot[su] += tot[sv];
}

int main () 
{
    for (int i = 0; i < N; i++) {
        sets[i] = i;
        tot[i] = 1;
    }

    int n;
    cin >> n;

    vector<pair<int, int>> heights;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heights.push_back(make_pair(x, i));
    }

    sort(heights.begin(), heights.end(), greater<pair<int, int>> ());

    int currN = 1;
    vector<bool> visited (n+1, false);

    vector<int> final (n+1);

    for (int i = 0; i < n; i++) {
        int posit = heights[i].second;
        int value = heights[i].first;
        visited[posit] = true;

        if (posit && visited[posit-1]) {
            merge(posit, posit-1);
        }
        if (posit < n-1 && visited[posit+1]) {
            merge(posit, posit+1);
        }
        int curs = tot[find(posit)];
        while (currN <= curs) {
            final[currN++] = value;
        }
    }

    for (int i = 1; i <= n; i++) cout << final[i] << " ";
    cout << "\n";

}

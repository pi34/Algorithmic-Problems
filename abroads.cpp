// https://www.codechef.com/problems/ABROADS

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int sets[100005];
int pops[100005];

multiset<int> all;

int find (int node) {
    if (sets[node] == node) return node;
    else return sets[node] = find(sets[node]);
}

void merge (int u, int v) {
    int su = find(u);
    int sv = find(v);
    if (su == sv) return;
    sets[sv] = sets[su];
    all.erase(all.find(pops[sv]));
    all.erase(all.find(pops[su]));
    pops[su] += pops[sv];
    all.insert(pops[su]);
}

void change (int u, int newPop, int oldPop) {
    int su = find(u);
    all.erase(all.find(pops[su]));
    pops[su] = pops[su] - oldPop + newPop;
    all.insert(pops[su]);
}

int main ()
{
    int n, m, q;
    cin >> n >> m >> q;

    int inpop[n];
    for (int i = 1; i <= n; i++) cin >> inpop[i];

    vector<pair<int, int>> edges(m+1);
    vector<bool> deleted(m+1, false);

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edges[i] = make_pair(x, y);
    }

    vector<int> queries [q+1];

    for (int i = 1; i <= q; i++) {
        char t;
        cin >> t;
        if (t == 'D') {
            int k;
            cin >> k;
            deleted[k] = true;
            queries[i].push_back(1);
            queries[i].push_back(edges[k].first);
            queries[i].push_back(edges[k].second);
        } else {
            int a, x;
            cin >> a >> x;
            int newp = inpop[a];
            int oldp = x;
            inpop[a] = x;
            queries[i].push_back(2);
            queries[i].push_back(a);
            queries[i].push_back(newp);
            queries[i].push_back(oldp);
        }
    }

    for (int i = 1; i <= n; i++) {
        sets[i] = i;
        pops[i] = inpop[i];
        all.insert(pops[i]);
    }

    for (int i = 1; i <= m; i++) {
        if (!deleted[i]) {
            merge(edges[i].first, edges[i].second);
        }
    }
    vector<int> ans (q+1);

    for (int i = q; i >= 1; i--) {
        ans[i] = *(--all.end());
        if (queries[i][0] == 1) {
            merge(queries[i][1], queries[i][2]);
        } else {
            change(queries[i][1], queries[i][2], queries[i][3]);
        }
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';

}

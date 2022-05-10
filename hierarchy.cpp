#include <iostream>
#include <vector>

using namespace std;

int n = 1000;

vector<int> set(n);

int find (int node) {
    int curr = set[node];
    if (curr == node) {
        return curr;
    } else {
        set[node] = find(curr);
        return set[node];
    }
}

int main ()
{
    cin >> n;

    int qualifications[n];
    for (int i = 0; i < n; i++) cin >> qualifications[i];

    int m;
    cin >> m;

    vector<pair<int, pair<int, int>>> prs (n);
    vector<int> heads (n, -1);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        x--;
        y--;

        prs.push_back(make_pair(z, make_pair(x, y)));
        heads[y] = x;
    }

    sort(prs.begin(), prs.end());

    int received[n];

    for (int i = 0; i < n; i++) {
        set[i] = i;
        received[i] = 0;
    }

    int tot = 0;

    for (pair<int, pair<int, int>> p: prs) {
        int set1 = find(p.second.first);
        int set2 = find(p.second.second);

        if (set1 != set2) {
            if (!received[p.second.second]) {
                tot += p.first;
                set[set2] = set1; 
                received[p.second.second] = 1;
            }
        }
    }

    int totl = 0;

    for (int i = 0; i < n; i++) {
        if (heads[i] == -1) {
            totl++;
            if (totl > 1) {
                tot = -1;
                break;
            }
        }
    }

    cout << tot << "\n";
}

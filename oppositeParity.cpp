// https://codeforces.com/contest/1272/problem/E

#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000

using namespace std;

const int N = 100001;


vector<int> adjList[N];

vector<int> fin(N, INF);

void bfs (vector<int> &firs, vector<int> &sec) {
    queue<int> que;
    vector<int> fin1(N, INF);

    for (auto k: firs) {
        que.push(k);
        fin1[k] = 0;
    }

    while (!que.empty()) {
        int curr = que.front();
        que.pop();

        for (auto p: adjList[curr]) {
            if (fin1[p] == INF) {
                fin1[p] = fin1[curr] + 1;
                que.push(p);
            }
        }
        
    }

    for (auto l: sec) {
        if (fin1[l] != INF) {
            fin[l] = fin1[l];
        } else {
            fin[l] = -1;
        }
    }
}

int main ()
{
    int n;
    cin >>n;

    vector <int> odd, even;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i+arr[i] < n) {
            adjList[i+arr[i]].push_back(i);
        }
        if (i-arr[i] >= 0) {
            adjList[i-arr[i]].push_back(i);
        }
    }

    bfs(even, odd);
    bfs(odd, even);

    for (int i = 0; i < n; i++) cout << fin[i] << "\n";
    
}

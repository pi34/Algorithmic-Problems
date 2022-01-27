// Solution to this: https://www.iarcs.org.in/inoi/contests/dec2004/Advanced-1.php

#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main ()
{
    ll n, m;
    cin >> n >> m;

    priority_queue<ll> arr;

    for (ll i = 0; i < n+m; ++i) {
        ll curr;
        cin >> curr;

        if (curr != -1) {
            arr.push(curr);
        } else {
            cout << arr.top() << endl;
            arr.pop();
        }
    }
    
}

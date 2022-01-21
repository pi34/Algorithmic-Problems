// Solution to this: https://www.iarcs.org.in/inoi/contests/sep2004/Advanced-1.php

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main () 
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> arr (n);

    for (ll i = 0; i < n; ++i) {
        int s, d;
        cin >> s >> d;
        arr[i].first = s+d;
        arr[i].second = s;
    }

    sort(arr.begin(), arr.end());

    ll blocked = 0;
    ll count = 0;

    for (ll i = 0; i < n; ++i) {
        pair<ll, ll> curr = arr[i];
        if (curr.second > blocked) {
            count++;
            blocked = curr.first;
        };
    }

    cout << count << endl;
}

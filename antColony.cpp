#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

ll gcd (ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int main ()
{
    ll n;
    cin >> n; 

    ll s[n];
    for (ll i = 0; i < n; i++) cin >> s[i];

    ll t;
    cin >> t;

    while (t--) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;

        ll minim = 100000000000;
        ll freq = 0;
        for (ll k = x; k <= y; k++) {
            if (minim == s[k]) {
                freq++;
            } else if (minim > s[k]) {
                minim = s[k];
                freq = 1;
            }
        }
        
        ll totGCD = s[x];
        for (ll j = x+1; j <= y; j++) {
            totGCD = gcd(s[j], totGCD);
        }

        if (totGCD == minim) {
            cout << (y-x+1) - freq << "\n";
        } else {
            cout << (y-x+1) << "\n";
        }

    }
}

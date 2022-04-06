#include <iostream>

using namespace std;

typedef long long ll;

ll leaves = 0;

ll gcd (ll a, ll b) {
    if (b == 0) {
        return a;
    };
    gcd(b, a % b);
};

void iep (ll i, ll lcm, ll size, ll K, ll len[], ll N) {

    if (K <= i) {
        return;
    };

    iep (i+1, lcm, size, K, len, N);

    ll lCM = (lcm * len[i]) / gcd(lcm, len[i]);

    if (size % 2 == 0) {
        leaves = leaves - (((N-1)/lCM) + 1);
    } else {
        leaves = leaves + (((N-1)/lCM) + 1);
    };

    iep (i+1, lCM, size+1, K, len, N);

}

int main ()
{
    ll n, k;
    cin >> n >> k;

    ll len[k];

    for (ll i = 0; i < k; ++i) {
        cin >> len[i];
    };

    iep(0, 1, 0, k, len, n);

    cout << leaves;

}

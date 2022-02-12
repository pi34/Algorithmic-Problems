// https://oj.uz/problem/view/JOI15_sterilizing

#include <iostream>

using namespace std;

typedef long long ll;

const ll N = 100005;
ll arr[N];
ll segTree[N*4];
ll mxTill[N*4];

#define mid ((l + r) >> 1)

void construct (ll l, ll r, ll pos)
{
    if (l == r) {
        segTree[pos] = mxTill[pos] = arr[l];
        return;
    }

    construct(l, mid, pos<<1);
    construct(mid+1, r, pos<<1|1);
    segTree[pos] = segTree[pos<<1] + segTree[pos<<1|1];
    mxTill[pos] = max(mxTill[pos<<1], mxTill[pos<<1|1]);
}


ll Sum (ll l, ll r, ll pos, ll q1, ll q2)
{
    if (q2 < l || q1 > r || l > r) {
        return 0;
    }
    if (q1 <= l && q2 >= r) {
        return segTree[pos];
    }

    return Sum (l, mid, pos<<1, q1, q2) + Sum (mid+1, r, pos<<1|1, q1, q2);
}

void regUp (ll l, ll r, ll pos, ll newVal, ll newPos) 
{
    if (l > r || l > newPos || r < newPos) return;
    if (l == r) {
        segTree[pos] = mxTill[pos] = newVal;
        return;
    }
    regUp (l, mid, pos<<1, newVal, newPos);
    regUp (mid+1, r, pos<<1 | 1, newVal, newPos);

    segTree[pos] = segTree[pos<<1] + segTree[pos<<1|1];
    mxTill[pos] = max(mxTill[pos<<1], mxTill[pos<<1|1]);
}

void Update (ll l, ll r, ll pos, ll strength, ll q1, ll q2)
{
    if (q2 < l || q1 > r || mxTill[pos] == 0 || l > r) {
        return;
    }

    if (l == r) {
        segTree[pos] /= strength;
        mxTill[pos] /= strength;
        return;
    }

    Update(l, mid, pos<<1, strength, q1, q2);
    Update(mid+1, r, pos<<1|1, strength, q1, q2);
    segTree[pos] = segTree[pos<<1] + segTree[pos<<1|1];
    mxTill[pos] = max(mxTill[pos<<1], mxTill[pos<<1|1]);
}

int main ()
{
    ll n, q, k;
    cin >> n >> q >> k;
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    construct(1, n, 1);

    for (ll i = 0; i < q; i++) {
        ll x, y, z;
        cin >> x >> y >> z;

        if (x == 1) {
            regUp(1, n, 1, z, y);
        } else if (x == 3) {
            cout << Sum(1, n, 1, y, z);
        } else {
            Update(1, n, 1, k, y, z);
        }

    }
}

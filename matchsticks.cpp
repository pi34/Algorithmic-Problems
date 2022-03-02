// https://www.codechef.com/problems/MSTICK

#include <iostream>
#include <vector>

using namespace std;

vector<int> b(100005);
vector<int> segTreeMin(400020);
vector<int> segTreeMax(400020);

void construct (int l, int r, int pos) {
    if (l == r) {
        segTreeMin[pos] = b[l];
        segTreeMax[pos] = b[l];
        return;
    }
    int mid = (l+r)/2;
    construct(l, mid, pos*2);
    construct(mid+1, r, pos*2+1);
    segTreeMin[pos] = min(segTreeMin[pos*2], segTreeMin[pos*2+1]);
    segTreeMax[pos] = min(segTreeMax[pos*2], segTreeMax[pos*2+1]);
}

int minT (int l, int r, int pos, int q1, int q2) {
    if (q2 <= l || q1 >= r) {
        return INT_MAX;
    }
    if (q1 <= l && q2 >= r) {
        return segTreeMin[pos];
    }
    int mid = (l+r)/2;
    return min(minT(l, mid, pos, q1, q2), minT(mid+1, r, pos, q1, q2));
}

int maxT (int l, int r, int pos, int q1, int q2) {
    if (q2 <= l || q1 >= r) {
        return INT_MIN;
    }
    if (q1 <= l && q2 >= r) {
        return segTreeMax[pos];
    }
    int mid = (l+r)/2;
    return max(maxT(l, mid, pos, q1, q2), maxT(mid+1, r, pos, q1, q2));
}

int main ()
{
    int n;
    cin >> n; 

    int b[n];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;

        int m = minT (1, n, 0, l, r);
        int M = maxT (1, n, 0, l, r);
        int Md = max(maxT (1, n, 0, 1, l-1), maxT (1, n, 0, r+1, n));

        cout << (m+max((M-m)/2, Md));

    }
}

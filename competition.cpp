// https://oj.uz/problem/view/NOI17_bestplace

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int X = 0;
    int Y = 0;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        X = X + x;
        Y = Y + y;
    }

    cout << (X/n) << " " << (Y/n) << "\n";
}

#include <iostream>

using namespace std;

int main ()
{
    int t;
    cin >> t;

    while (t--) {

        pair<int, int> vert1;
        pair<int, int> vert2;
        pair<int, int> vert3;

        cin >> vert1.first >> vert1.second;
        cin >> vert2.first >> vert2.second;
        cin >> vert3.first >> vert3.second;

        if (vert1.second == vert2.second && vert3.second < vert1.second) {
            cout << abs(vert1.first - vert2.first) << "\n";
        } else if (vert2.second == vert3.second && vert1.second < vert3.second) {
            cout << abs(vert2.first - vert3.first) << "\n";
        } else if (vert1.second == vert3.second && vert2.second < vert1.second) {
            cout << abs(vert1.first - vert3.first) << "\n";
        } else {
            cout << 0 << "\n";
        }

    }
}

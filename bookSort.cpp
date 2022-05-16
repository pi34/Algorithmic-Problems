// Solution to this: https://www.iarcs.org.in/inoi/contests/sep2005/Advanced-1.php.

#include <iostream>
#include <vector>
#include

using namespace std;

int main ()
{
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; ++i) {
        int curr;
        cin >> curr;
        int indx = upper_bound(arr.begin(), arr.end(), curr) - arr.begin();
        if (indx >= arr.size()) {
            arr.push_back(curr);
        } else {
            arr[indx] = curr;
        };
    }

    cout << n - arr.size() << endl;
}

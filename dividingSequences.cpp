// Dynamic Programming problem

#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

bool check (int m1, int m2) {
    if (m2 % m1 == 0) {
        return true;
    } else {
        return false;
    }
}

int divSeq (int a[], int n) {

    int arr[n];

    for (int k = 0; k < n; ++k) {
        arr[k] = 1;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; j++) {

            bool ans = check(a[j], a[i]);

            if (ans) {
                arr[i] = std::max(arr[i], arr[j]+1);
            }

        };
    };

    return *max_element(arr, arr+n);

}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 1; i <= n; ++i) cin >> a[i];

    cout << divSeq(a, n) << endl;

}

#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int arr[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> arr[i][j];
    };

    int cnt = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (arr[i][j] == 1) {
                cnt++;
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l <= j; l++) {
                        arr[k][l] = 1 - arr[k][l];
                    }
                }
            }
        }
    }

    cout << cnt << "\n";
}

#include <iostream>
#include <string>

using namespace std;

int dnp(int arr1[], int arr2[], int n1, int m1) {
    if (n1 == 0 || m1 == 0) {
        return 0;
    };
    if (arr1[n1-1] == arr2[m1-1]) {
        return dnp(arr1, arr2, n1-1, m1-1) + 1;
    } else {
        return max(dnp(arr1, arr2, n1-1, m1), dnp(arr1, arr2, n1, m1-1));
    };
};

int main()
{

    int n;
    cin >> n;
    
    int m;
    cin >> m;

    int a1[n];
    int a2[m];

    for (int i = 1; i <= n; ++i) cin >> a1[i];
    for (int j = 1; j <= m; ++j) cin >> a2[j];

    cout << dnp(a1, a2, n, m) << endl;

}

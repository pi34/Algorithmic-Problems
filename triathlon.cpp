#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[0] > v2[0];
}

int main () {
    
    int n = 3;
    cin >> n;

    int arr1[n];
    int arr2[n];
    int arr3[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i] >> arr2[i] >> arr3[i];
    }

    vector< vector<int> > newarr(n , vector<int> (2, 0));

    for (int i = 0; i < n; ++i) {
        newarr[i][0] = arr1[i];
        newarr[i][1] = i;
    }

    sort(newarr.begin(), newarr.end(), sortcol);

    int sum = 0;
    int minima = numeric_limits<int>::max();
    int countSum = 0;

    for (int i = 0; i < n; ++i) {
        int curr = newarr[i][1];
        int dsum = arr2[curr] + arr3[curr];
        int currsum = arr2[curr] + arr3[curr] + arr1[curr];

        countSum = countSum + arr1[curr];

        if (dsum < minima) {
            minima = dsum;
        };

        if (currsum > countSum + minima) {
            sum = currsum;
        } else {
            sum = countSum + minima;
        };
    }

    cout << sum << endl;

}

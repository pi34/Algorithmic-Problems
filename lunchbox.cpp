#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(m);

    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    };

    sort(arr.begin(), arr.end());

    int cnt = 0;

    while (n > 0) {
        n = n - arr[cnt];
        cnt++;
        cout << cnt << "u" << endl;
    }

    cout << cnt-1 << endl;

}

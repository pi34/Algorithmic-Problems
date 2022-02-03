// https://codebreaker.xyz/problem/catlunch

#include <iostream>
#include <queue>

using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    priority_queue<int> curr;

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        if (curr.size() < k) {
            int var;
            cin >> var;
            curr.push(var);
        } else if (curr.size() == k) {
            int max = curr.top();
            if (max <= 0) {
                break;
            } else {
                sum = sum + curr.top();
                curr.pop();
            }
        }
    }

    cout << sum << "\n";

}

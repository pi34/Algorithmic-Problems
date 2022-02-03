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
    int i = 0;

    while (i < n) {
        if (curr.size() < k) {
            int var;
            cin >> var;
            curr.push(var);
            i++;
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

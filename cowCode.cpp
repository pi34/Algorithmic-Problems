// Solution to this problem: http://usaco.org/index.php?page=viewproblem2&cpid=692.

#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

int main () {

    int n;
    cin >> n;

    string str;
    cin >> str;

    int len = str.size();
    int calc = (log((n-1)/ len)+1) / log(2);
    int powr = pow(2, calc) * len;
    
    int i = powr;
    int a = n;

    while (a >= len) {
        int curr = i - a + 1;
        i = i / 2;
        a = i - curr;
    }

    cout << str[a-1] << endl;

}

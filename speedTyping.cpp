#include <iostream>
#include <string.h>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        string I, P;
        cin >> I >> P;
        
        int n = I.length();
        int m = P.length();
        
        int ptI = 0;
        int ptP = 0;
        
        while (ptI < n && ptP < m) {
            if (I[ptI] == P[ptP]) {
                ptI++;
                ptP++;
            } else {
                ptP++;
            }
        }
        
        if (ptI == n) {
            cout << "Case #" << i << ": " << m-n << "\n";
        } else {
            cout << "Case #" << i << ": " << "IMPOSSIBLE" << "\n";
        }
    }
}

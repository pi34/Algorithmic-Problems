// Solution to this problem: https://www.codechef.com/problems/TLG.

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	int first = 0;
    int second = 0;

    int player;
	int lead = 0;
	int curr;

	for (int i = 1; i <= n; ++i) {

        int fir;
        int sec;

        cin >> fir >> sec;
        
        first = first + fir;
        second = second + sec;
        
        curr = first - second;
        
        fir = 0 ;
        sec = 0;

        if (curr >= 0) {
	        if (curr > lead) {
	            lead = curr;
	            player = 1;
	        } 
	    } else {
	        curr = second - first;
	        
	        if (curr > lead) {
	            lead = curr;
	            player = 2;
	        }
	    }

	};
	
	cout << player << " " << lead << endl;
}

#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int curr = 9;
    bool win = true;

    while ((n+curr-1)/curr > 1) {

        if (win) {
            curr = curr * 2;
            win = false;
        } else {
            curr = curr * 9;
            win = true;
        };

    };

    if (win) {
        cout << "Player 1" << endl;
    } else {
        cout << "Player 2" << endl;
    }
    
}

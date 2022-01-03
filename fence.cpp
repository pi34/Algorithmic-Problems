#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main () {
    int r, c, n;
    cin >> r >> c >> n;

    int matrix[r][c];
    int marked[r][c];

    int edges[n][2];

    for (int j = 0; j < r; ++j) {
        for (int k = 0; k < c; ++k) {
            marked[j][k] = 0;
            matrix[j][k] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {

        int currx, curry;
        cin >> currx >> curry;
        edges[i][0] = currx-1;
        edges[i][1] = curry- 1;
        matrix[currx-1][curry-1] = 1;

    }

    int grTot = 0;

    for (int j = 0; j < n; ++j) {

        int currX = edges[j][0];
        int currY = edges[j][1];

        if (matrix[currX][currY] == 1 && marked[currX][currY] == 0) {

            int tot = 0;
            deque<int> queueX;
            deque<int> queueY;
            queueX.push_back(currX);
            queueY.push_back(currY);

            while (!(queueX).empty() && !(queueY).empty()) {

                int fenceing = 0;

                int nodeX = queueX.front();
                int nodeY = queueY.front();

                for (int i = 0; i < sizeof(queueX); ++i) {
                    cout << queueX[i] << " " << queueY[i] << endl;
                }

                queueX.pop_front();
                queueY.pop_front();

                if (marked[nodeX][nodeY] != 1) {

                    marked[nodeX][nodeY] = 1;
                    cout << marked[nodeX][nodeY];


                    if (nodeX+1 < r && nodeY < c) {
                        if (matrix[nodeX+1][nodeY] == 1) {
                            fenceing = fenceing + 1;
                            cout << "ynu";
                            if (marked[nodeX+1][nodeY] == 0) {
                                queueX.push_back(nodeX+1);
                                queueY.push_back(nodeY);
                            }
                        }
                    }

                    if (nodeX-1 >= 0 && nodeY < c) {
                        if (matrix[nodeX-1][nodeY] == 1) {
                            fenceing = fenceing + 1;
                            cout << "yes";
                            if (marked[nodeX-1][nodeY] == 0) {
                                queueX.push_back(nodeX-1);
                                queueY.push_back(nodeY);
                            }
                        }
                    }

                    if (nodeX < r && nodeY+1 < c) {
                        if (matrix[nodeX][nodeY+1] == 1) {
                            fenceing = fenceing + 1;
                            cout << "yosa";
                            if (marked[nodeX][nodeY+1] == 0) {
                                queueX.push_back(nodeX);
                                queueY.push_back(nodeY+1);
                            }
                        }
                    }
                    
                    if (nodeX < r && nodeY-1 >= 0) {
                        if (matrix[nodeX][nodeY-1] == 1) {
                            fenceing = fenceing + 1;
                            cout << "yestfg";
                            if (marked[nodeX][nodeY-1] == 0) {
                                queueX.push_back(nodeX);
                                queueY.push_back(nodeY-1);
                            }
                        }
                    }

                    if (fenceing == 1) {
                        tot = tot + 3;
                    } else if (fenceing == 2) {
                        tot = tot + 2;
                    } else if (fenceing == 3) {
                        tot = tot + 1;
                    } else if (fenceing == 0) {
                        tot = tot + 4;
                    }

                    cout << fenceing << " " << nodeX << " " << nodeY << endl;

                }

            }

            if ( tot > grTot ) {
                grTot = tot;
            };
        }

    }

    cout << grTot << endl;

}

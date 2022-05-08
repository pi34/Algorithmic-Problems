#include <iostream>

using namespace std;

int main () {

    int K;
    cin >> K;

    int n, m;
    cin >> n >> m;

    int matrix[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        };
    };

    int sum[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i][j] = matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]
        }
    }

    int bR1 = 0;
    int bR2 = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int rectangleOne = 0;
            int rectangleTwo = 0;
            for (int k = 0; k < i; ++k) {
                int start = 0;
                int end = 0;
                int curr = 0;
                while (start >=0 && start < n && end >= 0 && end < n) {
                    curr = (sum[i][end] - sum[i][start-1] - sum[k-1][end] + sum[k-1][start-1]);
                    if (curr == K) {
                        int perim = 2*((end-start+1)+(i-k+1));
                        if (perim > rectangleOne) {
                            rectangleOne = perim;
                        }
                    } else if (curr < K) {
                        end++
                    } else if (curr > K) {
                        start++
                    }
                }
            }
            for (int l = i; l < n; ++l) {
                int start2 = 0;
                int end2 = 0;
                int curr2 = 0;
                while (start2 >=0 && start2 < n && end2 >= 0 && end2 < n) {
                    curr2 = (sum[l][end2] - sum[l][start2-1] - sum[i-1][end2] + sum[i-1][start2-1]);
                    if (curr2 == K) {
                        int perim = 2*((end2-start2+1)+(i-l+1));
                        if (perim > rectangleTwo) {
                            rectangleTwo = perim;
                        }
                    } else if (curr < K) {
                        end2++
                    } else if (curr > K) {
                        start2++
                    }
                }
            }
            for (int p = 0; p < j; ++p) {
                int startY = 0;
                int endY = 0;
                int currY = 0;
                while (startY >=0 && startY < m && endY >= 0 && endY < m) {
                    currY = (sum[endY][j] - sum[endY][p-1] - sum[startY-1][j] + sum[startY-1][p-1]);
                    if (curr == K) {
                        int perim = 2*((end-start+1)+(i-k+1));
                        if (perim > rectangle) {
                            rectangle = perim;
                        }
                    } else if (curr < K) {
                        end++
                    } else if (curr > K) {
                        start++
                    }
                }
            }
            for (int p = 0; )
            if (rectangleOne < bR1 && rectangleTwo < bR2) {
                bR1 = rectangleOne
                bR2 = rectangleTwo
            }
            if (rectangleTwo < bR1 && rectangleOne < bR1) {
                bR2 = rectangleOne
                bR1 = rectangleTwo
            }
        }
    }

}

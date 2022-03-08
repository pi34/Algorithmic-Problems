// Solution to this problem: https://www.iarcs.org.in/inoi/contests/oct2005/Advanced-2.php

#include <iostream>
#include <vector>

using namespace std;

vector< vector< int > > mult (vector< vector< int > > mat1, vector< vector< int > > mat2) 
{
    int size = mat1.size();
    vector< vector< int > > final( size, vector< int > ( size, 0 ) );
    for( int i = 0; i < size; i++ )
	{
		for( int j = 0; j < size; j++ )
		{
			for( int k = 0; k < size; k++ )
			{
				final[i][j] = ( final[i][j] + mat1[i][k] * mat2[k][j] ) % 42373;
			}
		}
	}
	return final;
}

int main ()
{
    int n;
    cin >> n;

    vector<vector<int>> matr (n, vector<int> (n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matr[i][j];
        }
    }

    int src, dest, k;
    cin >> src >> dest >> k;

    vector<vector<int>> final (n, vector<int> (n, 0));

    for (int i = 0; i < n; ++i) {
        final[i][i] = 1;
    }

    int currK = k;

    while (currK > 0) {
        if (currK % 2) {
            final = mult(final, matr);
        }
        matr = mult(matr, matr);
        currK = currK / 2;
    };

    cout << final[src-1][dest-1] % 42373 << endl;
}

#ifndef MAX_PIECE_OF_MATRIX_H
#define MAX_PIECE_OF_MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

int sum_subarray(std::vector< std::vector<int> >  A,int i,int j,int width,int height)
{
    int sum=0;

    for(int n=i;n<width;n++)
        for(int m=j;m<height;m++)
            sum+=A[n][m];

    return sum;
}

void example()
{
    const int M=3,N=4;
    const int tempA[M][N] = {{1,2,3,4}, {5,6,7,8},{9,-10,11,-12}};

    vector< vector<int> > A(M, std::vector<int>(N));

    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
        {
            A[i][j]=tempA[i][j];
            cout<<A[i][j];
        }

    int maxSum = A[0][0];
    int maxI0 = 0, maxJ0 = 0, maxI1 = 1, maxJ1 = 1;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
          for (int width = 1; width <= M - i; width++)
            for (int height = 1; height <= N - j; height++)
            {
              int currentSum = sum_subarray(A, i, j, i + width, j + height);
              if (currentSum > maxSum)
              {
                maxSum = currentSum;
                maxI0 = i;
                maxJ0 = j;
                maxI1 = i + width - 1;
                maxJ1 = j + height - 1;
              }
            }
    cout << "Max subarray: [" << maxI0 << "][" << maxJ0 << "] .. [" << maxI1 << "][" << maxJ1 << "]";
    cout << endl <<  "Max value = " << maxSum << endl;
    cout << "Area = " << (maxI1 - maxI0 + 1) * (maxJ1 - maxJ0 + 1) << endl;
}



#endif // MAX_PIECE_OF_MATRIX_H

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
    private:
        long int **Matr;
        long int m;
        long int n;

        void Create()
        {
            Matr = new long int*[m];
            for (int z=0; z<m; z++)
                Matr[z] = new long int[n];
        }

    public:
        Matrix(): m(5), n(5) { Create(); }
        Matrix(long int i): m(i), n(i) { Create(); }
        Matrix(long int i, long int j): m(i), n(j) { Create(); }
        ~Matrix()
        {
            for (int z=0; z<m; z++)
                delete[] Matr[z];
            delete[] Matr;
        }

        long int& Element(long int i, long int j)
        {
            if (i<m && j<n)
                return Matr[i][j];
            else
                cout << "Error: 1";
        }

        void MultiplyBy(long int x)
        {
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    Matr[i][j] *= x;
        }

        void Display()
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cout.width(4);
                    cout << Matr[i][j];
                }
                cout << endl;
            }
        }

};


void example()
{
    Matrix M(5,5);

    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
            M.Element(i, j) = i+j;
    }

    M.Display();

    M.MultiplyBy(5);
    M.Display();

}


#endif // MATRIX_H

#ifndef SADDLE_POINT_H
#define SADDLE_POINT_H

#include <iostream>
#include <vector>
using namespace std;

bool Min(int m,int v,vector< vector<int> > mas)
{
        int min=mas[m][v];
        for(int i=0;i<mas.size();i++)
                if(min>mas[i][v])
                        return false;
        return true;
}

bool Max(int m,int v,vector< vector<int> > mas)
{
        int max=mas[m][v];
        for(int i=0;i<mas.size();i++)
                if(max<mas[m][i])
                        return false;
        return true;
}

void example()
{

        const int m=4,n=4;
        const int temp[m][n] = {{2,3,5,20}, {2,4,6,20},{2,7,2,10},{2,7,2,10}};

        vector< vector<int> > mas(m, std::vector<int>(n));



        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mas[i][j]=temp[i][j];
                cout<<mas[i][j]<<" ";
            }
            cout<<endl;
        }



        int c=0;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if(Min(i,j,mas) && Max(i,j,mas))
                        {
                                c++;
                                cout<<i<<' '<<j<<endl;
                        }
                }
        }

        if(c==0)
                cout<<"No";
}



#endif // SADDLE_POINT_H

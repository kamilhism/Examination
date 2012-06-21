#ifndef A_B_H
#define A_B_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/// создание вектора
 vector<int> insert(char c[])
 {
         vector<int> a;

         int k=0;

         while(c[k]!='\0')
            {
                    a.push_back((int)c[k]-'0');
                    k++;
            }

         return a;
 }

vector<int> zero(vector<int> a)
{
        bool f=false;
        int razmer=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i]!=0)
            {
                f=true;
                razmer=i;
                break;
            }
        }

        if(f)
        {
            vector<int> b(razmer+1);
            for(int i=0;i<razmer+1;i++)
                b[i]=a[razmer-i];

            return b;
        }
        else
            return a;


}
vector<int> summa(vector<int> a,vector<int> b)
{


        if(a.size()>b.size())
        {
            vector<int> rez(3000);
            int a_end=a.size()-1;
            int ostatok=0,k=0,otv;
            for(int i=b.size()-1;i>=0;i--)
            {
                otv=a[a_end]+b[i]+ostatok;

                if(otv>9)
                {
                    rez[k]=otv%10;
                    ostatok=otv/10;
                }
                else
                {
                    rez[k]=otv;
                    ostatok=0;
                }
                k++;
                a_end--;
            }

            int kk=k;
            for(int i=a.size();i>kk;i--)
            {
                otv=a[a_end]+ostatok;

                if(otv>9)
                {
                    rez[k]=otv%10;
                    ostatok=otv/10;
                }
                else
                {
                    rez[k]=otv;
                    ostatok=0;
                }
                k++;
                a_end--;
            }

            if(ostatok!=0)
            {
                rez[k]=ostatok;
            }

            return zero(rez);

        }
        else
        {
            vector<int> rez(3000);
            int b_end=b.size()-1;
            int ostatok=0,k=0,otv;
            for(int i=a.size()-1;i>=0;i--)
            {
                otv=b[b_end]+a[i]+ostatok;

                if(otv>9)
                {
                    rez[k]=otv%10;
                    ostatok=otv/10;
                }
                else
                {
                    rez[k]=otv;
                    ostatok=0;
                }
                k++;
                b_end--;
            }

            int kk=k;
            for(int i=b.size();i>kk;i--)
            {
                otv=b[b_end]+ostatok;

                if(otv>9)
                {
                    rez[k]=otv%10;
                    ostatok=otv/10;
                }
                else
                {
                    rez[k]=otv;
                    ostatok=0;
                }
                k++;
                b_end--;
            }

            if(ostatok!=0)
            {
                rez[k]=ostatok;
            }

            return zero(rez);

        }


}

int sravnenie(vector<int> a,vector<int> b)
{
        if(a.size()>b.size())
            return 1;
        if(b.size()>a.size())
            return 2;

        int r=0;

        for(int i=0;i<a.size();i++)
        {
            if(a[i]>b[i])
            {
                r=1;
                break;
            }
            if(b[i]>a[i])
            {
                r=2;
                break;
            }

        }

        return r;
}
vector<int> zero2(vector<int> a,int n)
{
        bool f=false;
        int razmer=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i]!=0)
            {
                f=true;
                razmer=i;
                break;
            }
        }

        if(f)
        {
            vector<int> b(razmer+1+n);
            for(int i=0;i<razmer+1;i++)
                b[i]=a[razmer-i];

            for(int i=razmer+1;i<razmer+1+n;i++)
                b[i]=0;

            return b;
        }
        else
            return a;


}
vector<int> proizved(vector<int> a,vector<int> b)
{
        vector<int> prev(1001);
        vector<int> cur(1001);
        vector<int> rez(3000);

        int a_end=a.size()-1;

        int ostatok=0,k=0,otv,zer=0;

        for(int i=b.size()-1;i>=0;i--)
        {

            for(int j=a.size()-1;j>=0;j--)
            {

            otv=a[j]*b[i]+ostatok;

            if(otv>9)
            {
                cur[k]=otv%10;
                ostatok=otv/10;
            }
            else
            {
                cur[k]=otv;
                ostatok=0;
            }
            k++;

            }

            if(ostatok!=0)
            {
                cur[k]=ostatok;
                ostatok=0;
            }

            cur=zero2(cur,zer);

            prev=summa(prev,cur);
            zer++;
            k=0;
        }

        return prev;

}

void example()
{

        ifstream f("input.txt");

        vector<int> a;
        char c[10000];
        f.getline(c,10000,'\n');
        a=insert(c);


        vector<int> b;
        char c2[10000];
        f.getline(c2,10000,'\n');
        b=insert(c2);

        f.close();




        ofstream f2("output.txt");

        vector<int> rez;

        char operation='*';
        bool m=false;
        int srav=sravnenie(a,b);


        switch(operation)
             {
             case '*':
                if(srav==1 || srav==0)
                     rez=proizved(a,b);
                else
                    rez=proizved(b,a);
                     break;
             }


        if(rez[0]!=0)
            for(int i=0;i<rez.size();i++)
            f2<<rez[i];
        else
            f2<<"0";


            f2.close();

}




#endif // A_B_H

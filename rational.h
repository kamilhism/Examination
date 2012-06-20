#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

int nod(int a,int b)
{
    a=abs(a);
    b=abs(b);

    if(a==b)
        return a;
    if(b>a)
        return nod(a,b-a);
    if(a>b)
        return nod(a-b,b);
}
int nok(int x, int y)
{
  int prod = x * y;
  int Nod = nod(x,y);
  int nok = prod / Nod;

  return nok;
}
class rational{
    friend ostream& operator <<(ostream &s,rational *c);
private:
    int n,m;
public:
    rational(int,int);
    void print();
    double double_rezult();

    bool operator<(rational r2)
    {
        if(this->double_rezult()<r2.double_rezult())
            return 1;
        else
            return 0;
    }
    rational* operator+(rational r2)
    {
        int Nok=nok(this->m,r2.m);

        return new rational(Nok/this->m*this->n+Nok/r2.m*r2.n,Nok);
    }
    rational* operator-(rational r2)
    {
        int Nok=nok(this->m,r2.m);

        return new rational(Nok/this->m*this->n-Nok/r2.m*r2.n,Nok);
    }
    rational* operator*(rational r2)
    {
        int n2,m2;

        n2=this->n*r2.n;
        m2=this->m*r2.m;
        int NOD=nod(n2,m2);

        return new rational(n2/NOD,m2/NOD);
    }
    rational* div (rational r2)
    {
        int n2,m2;

        n2=this->n*r2.m;
        m2=this->m*r2.n;
        int NOD=nod(n2,m2);

        return new rational(n2/NOD,m2/NOD);
    }

};
ostream& operator<<(ostream &s,rational *c)
{
    s<<c->n<<"/"<<c->m<<endl;
    return s;
}
rational::rational(int n,int m)
{
    if(m==0)
    {
        throw "error";
    }

    int NOD=nod(n,m);

    this->n=n/NOD;
    this->m=m/NOD;
}
double rational::double_rezult()
{
    return (double)n/(double)m;
}
void example()
{
    rational* r=new rational(2,6);
    cout<<"a: "<<r;

    rational* r2=new rational(2,4);
    cout<<"b: "<<r2;

    if(*r2<*r)
        cout<<"b < a";
    else
        cout<<"b > a";

    cout<<endl<<"a+b= "<<(*r+*r2);

    cout<<"a-b= "<<(*r-*r2);

    cout<<"a*b= "<<(*r**r2);

    cout<<"a/b= "<<(r->div(*r2));


    cout<<endl;
}






#endif // RATIONAL_H

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class vector
{
    int *v;
    int sz;
public:
    vector(int);
    ~vector();

    int size() {return sz;}
    void set_size(int);
    int &operator[](int);
    int &elem(int i) {return v[i];}
};

vector::vector(int s)
{
    if(s<=0)
        throw "bad size";

    sz=s;
    v=new int[s];
}
int &vector::operator [](int i)
{
    if(i<0 || sz<=i)
        throw "out of range";

    return v[i];
}
vector::~vector()
{
    delete v;
}
void example()
{
    int n=5;
    vector a(n);

    for(int i=0;i<n;i++)
    {
        a[i]=i;
        cout<<a[i];
    }


}

#endif // VECTOR_H

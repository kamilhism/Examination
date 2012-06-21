#ifndef ACKERMANN_H
#define ACKERMANN_H

#include <iostream>
#include <stack>
using namespace std;

void example()
{
    int m=1,n=4;

    stack<int> s;

    s.push(m);

    while(!s.empty()){

        m=s.top();
        s.pop();

        if(m==0||n==0)
            n+=m+1;
        else{
            s.push(--m);
            s.push(++m);
            n--;
        }
    }

     cout<<n;
}



#endif // ACKERMANN_H

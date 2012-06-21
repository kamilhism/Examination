#ifndef SKOBKI_H
#define SKOBKI_H

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void example()
{
    string s="(2+1)*[3-3]*4";

    stack<char> st;

    bool error=false;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='[')
            st.push(s[i]);
        else
        {
            if((s[i]==')' || s[i]==']') && st.empty())
            {
                error=true;
                break;
            }

            if(s[i]==')')
                if(st.top()=='(')
                    st.pop();
                else
                    error=true;
            else
                if(s[i]==']')
                    if(st.top()=='[')
                        st.pop();
                    else
                        error=true;
        }
        if(error)
            break;
    }

    if(error || !st.empty())
        cout<<"error";
    else
        cout<<"correct";
}


#endif // SKOBKI_H

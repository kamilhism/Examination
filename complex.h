#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <iostream>

using namespace std;

class complex
{
     private:
            float real;
            float imag;
   public:
          complex(float,float);
          complex(const complex &);
          complex operator +(complex);
          complex operator -(complex);
          complex operator *(complex);
          complex operator /(complex);
          float modul();
          bool operator ==(complex);
          void operator=(complex);
          friend ostream& operator <<(ostream &s,complex &c);
};
            complex::complex(float r=0.0f,float im=0.0f)
            {
                real=r;
                imag=im;
            }
            complex::complex(const complex &c)
            {
                this->real=c.real;
                this->imag=c.imag;
            }
            void complex::operator =(complex c)
            {
                real=c.real;
                imag=c.imag;
            }


            complex complex::operator +(complex c)
            {
               complex tmp;
               tmp.real=this->real+c.real;
               tmp.imag=this->imag+c.imag;
               return tmp;
            }

            complex complex::operator -(complex c)
            {
               complex tmp;
               tmp.real=this->real - c.real;
               tmp.imag=this->imag - c.imag;
               return tmp;
            }

            complex complex::operator *(complex c)
            {
               complex tmp;
               tmp.real=(real*c.real)-(imag*c.imag);
               tmp.imag=(real*c.imag)+(imag*c.real);
               return tmp;
            }

            complex complex::operator /(complex c)
            {
               float div=(c.real*c.real) + (c.imag*c.imag);
               complex tmp;
               tmp.real=(real*c.real)+(imag*c.imag);
               tmp.real/=div;
               tmp.imag=(imag*c.real)-(real*c.imag);
               tmp.imag/=div;
               return tmp;
            }

            float complex::modul() //Ìîäóëü êîìïëåêñíîãî ÷èñëà
            {
               float z;
               z=(real*real)+(imag*imag);
               z=sqrt(z);
               return z;
            }

            bool complex::operator ==(complex c)
            {
                return (real==c.real)&&(imag==c.imag) ? 1 : 0;
            }

            ostream& operator <<(ostream &s,complex &c)
            {
                s<<"z = "<<c.real<<setiosflags(ios::showpos)
                <<c.imag<<"i"<<endl<<resetiosflags(ios::showpos);
                return s;
            }



void example()
{
       complex a(10,-2);
       cout<<a<<endl;

       complex b(-2,10);
       complex c=b;
       cout<<b<<endl;

       if(b==c)
          cout<<"b == c";
       else
          cout<<"b != c";


       cout<<endl<<c.modul()<<endl;

       complex d;

       d=a+b;
       cout<<d<<endl;

       d=a-b;
       cout<<d<<endl;

       d=a*b;
       cout<<d<<endl;

       d=a/b;
       cout<<d<<endl;

}


#endif // COMPLEX_H

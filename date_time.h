#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
    friend ostream& operator <<(ostream &s,Date d);
 public:
    Date (int hour,int minut,int month, int day, int year);
    void display();
 private:
    int hours, minuts, months, days, years;
};
 Date::Date (int hour=1, int minut=1, int month=1, int day=1, int year=1)
{
     if(hour>23 || minut>59 || month>12 || day>31 || hour<0 ||
        minut<0 || month<1 || year<1)
         throw "bad date";

     hours=hour;
     minuts=minut;
     months=month;
     days=day;
     years=year;

}
 ostream& operator<<(ostream &s,Date d)
 {
     s<<d.hours<<":"<<d.minuts<<", "<<d.days<<"/"<<d.months<<"/"<<d.years<<endl;
     return s;
 }

void example()
{
    Date d(12,23,1,2,2012);
    cout <<d;
}


#endif // DATE_TIME_H

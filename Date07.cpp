#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Date07.h"
#include "Amortization07.h"
using namespace std;
//Constructor that takes a principal, monthly interest and number of months. Uses parameters to create an Amortization object
Date::Date(double p, double i, double n)
{
        a=Amortization(p,i,n);
}
//returns the month variable of the abbreviation of the month name
string Date::getMonth(void)
{
        return month;
}
//returns the monthly payment of the loan using the findR function from the Amortization class
double Date::getR(void)
{
        return a.findR();
}
//returns the day of the month the loan is due
int Date::getDay(void)
{
        return day;
}
//returns the year that the first payment of the loan occurs
int Date::getYear(void)
{
        return year;
}
//accepts an int parameter and sets the year variable to the passed value
void Date::setY(int y)
{
        year=y;
}
//accepts an int parameter and sets the day variable to the passed value
void Date::setD(int d)
{
        day=d;
}
//accepts an int parameter and sets the m variable to the passed value and updates the month variable using m value
void Date::setM(int mon)
{
        m=mon;
        month=monthNames[m];
}
//makes the header for the beginning of the file and when a new year occurs formating with setw and setfill
void Date::newYear(void)
{
        o << setw(11) <<setfill(' ') << "Due Date";
        o<<" ";
        o<<setw(12) <<setfill(' ') << "Payment ";
        o<<setw(13) <<setfill(' ') << "Monthly ";
        o<<setw(2)<<" ";
        o<<setw(11)<<setfill(' ') << "Monthly ";
        o<<setw(12)<<setfill(' ') <<"Monthly ";
        o<<setw(12)<<setfill(' ') << "Balance ";
        o<<setw(12)<<setfill(' ') << "Yearly ";
        o<<setw(12)<<setfill(' ') << "Yearly ";
        o<<endl;
        o<<setw(24)<<setfill(' ')<<"Number ";
        o<<setw(13)<<setfill(' ')<<"Payment ";
        o<<setw(13)<<setfill(' ')<<"Interest ";
        o<<setw(12)<<setfill(' ')<<"Principal ";
        o<<setw(24)<<setfill(' ')<<"Interest ";
        o<<setw(12)<<setfill(' ')<<"Principal ";
       o<<endl;
}
//Prints out each individual line in the row sligning with the correct collumn using setw,setfill and right alignment
void Date::newLine(int num)
{
        string d=to_string(day)+" "+month+" "+to_string(year);
        o<<setw(11)<<setfill(' ')<<right<<d;
        o<<setw(12)<<right<<setfill(' ')<<num;
        o<<setw(2)<<" ";
        o<<right<<setw(11)<<setfill(' ')<<fixed<<setprecision(2)<<getR();
        o<<right<<setw(13)<<setfill(' ')<<fixed<<setprecision(2)<<a.findMi();
        o<<right<<setw(12)<<setfill(' ')<<fixed<<setprecision(2)<<a.findMp();
        o<<right<<setw(12)<<setfill(' ')<<fixed<<setprecision(2)<<a.getB();
        o<<right<<setw(12)<<setfill(' ')<<fixed<<setprecision(2)<<a.getYi();
        o<<right<<setw(12)<<setfill(' ')<<fixed<<setprecision(2)<<a.getYp();
        o<<endl;
}
//Makes the entire automortization file
void Date::makeAuto(void)
{
        //opens a07.dat with the ofstream variable
        o.open("a07.dat");
        //runs the newYear function
        newYear();
        //uses a for loop with i and the month number incrementing and loops until i is equal to the value of the number of months to pay
        for(int i=1,mon=m; i<=a.getN(); i++,mon++)
        {
                //if month is greater then 11 so it's a new year
                if(mon>11)
                {
                        //run the resetYearly function
                        a.resetYearly();
                        //format an endline in the file
                        o<<endl;
                        //runs the newYear function to make the needed headers in the file for a new year
                        newYear();
                        //resets the value of the month to 0 so it's set back to January
                        mon=0;
                        //increments the year variable for the new year
                        year++;
                }
                //runs the updateB function from the amortization object
                a.updateB();
                //updates the month abbreviation with the incremented value of mon using the monthNames string array
                month=monthNames[mon];
                //runs the newLine function with the value of i to be used as the payment number
                newLine(i);
        }
}

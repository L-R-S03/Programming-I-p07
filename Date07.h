#ifndef Date07_h
#define Date07_h 1
#include <iostream>
#include <fstream>
#include "Amortization07.h"
using namespace std;
class Date
{
        Amortization a; // Amortization object to access the needed calculations and values to write to the output file
        int day,year,m; //ints for the day year and month number the loan begins being due
        string month;   //string value for the abbreviated month name
        ofstream o;
        string monthNames[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"}; //Array with month names in order
public:
        Date(double p, double i, double n);
        void makeAuto(void);
        void newYear(void);
        void setY(int y);
        string getMonth(void);
        int getYear(void);
        int getDay(void);
        void setD(int d);
void setM(int mon);
        double getR(void);
        void newLine(int num);

};
#endif 

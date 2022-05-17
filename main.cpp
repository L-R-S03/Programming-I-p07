#include <iostream>
#include <iomanip>
#include "Date07.h"
using namespace std;

//Prompts for the Principal amount and reads in the entered value. Prints out the principal and returns it.
double Principal(void)
{
        double p=0;
        cout << "Enter the principal. ";
        cin >>  p;
        cout << "P=$" << fixed << setprecision(2) << setfill('0')  << p<< endl;
        return p;
}

//Prompts for the APR value and reads in the entered value. Computes the monthly interest and returns the monthly interest.
//Prints out both the apr and the monthly interest

double APR(void)
{
        double apr, i=0;
        cout << "Enter the Annual Percentage Rate (APR). ";
        cin >> apr;
        i=apr/1200;
        cout << "i=" <<fixed<< setprecision(6) <<  i << ", APR=" << setprecision(2)  << apr << endl;
        return i;
}

//prompts for the number of years in the term and reads in the entered value. Computes and returns the number of months;
//Prints out the number of years and the number of months;
double n(void)
{
        double y;
        int n;
        cout << "Enter the number of years in the term. ";
        cin >> y;
        n=y*12;
        cout << "n=" << fixed  << n << " months, " << y << " years." <<endl;
        return n;
}
//Prompts for the number of the month that the first payment is due. Reads in and returns the entered value.
int month(void)
{
        int m;
        cout << "Enter the month (1...12) when the first payment is due. ";
        cin >> m;
        return m-1;
}
//prompts for the number in the month that the payment is due. Reads in and returns the entered value.
int day(void)
{
        int d;
        cout << "Enter the day of the month (1...28) when the first payment is due. ";
        cin >> d;
        return d;
}
//Prompts the user for the year the first payment is due. Reads in and returns the entered values
int year(void)
{
        int y;
        cout << "Enter the year when the first payment is due. ";
        cin >> y;
        return y;

}
int main()
{
        double p,i,num;
        int m,d,y;
        //use the above functions to prompt for and collect values for the principal, apr and number of months
        p=Principal();
        i=APR();
        num=n();
        //creates a date object with the principal, monthly interest and number of months as parameters
        Date D(p,i,num);
        //prints out the monthly payment using the getR functions from the Date class
        cout << "R=$" << D.getR() <<endl;
        //prompts the value of the month, day and year the loan is due and sets the values
        //of the correct variables in the Date class using the set functions from the Date class
        D.setM(month());
        D.setD(day());
        D.setY(year());
        //Prints out the month, day and year the first payment is due using the get functions from the Date class
        cout << D.getMonth() << " " << D.getDay() << " " << D.getYear() <<  endl;
        cout << "The mortgage amortization schedule is in file a07.dat" << endl;
        //runs the makeAuto from the Date class to make the amortization schedule in file a07.dat
        D.makeAuto();
        return 0;
}

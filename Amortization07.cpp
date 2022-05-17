#include <iostream>
#include <iomanip>
#include <cmath>
#include "Amortization07.h"
using namespace std;
//Creates an empty Amortization object
Amortization::Amortization(){}
//Constructor that accepts the principal, monthly interest and number of months.
//Sets class variables to correct parameters and initilizes the yearly interest and yearly payment to 0
Amortization::Amortization(double p, double interest,int num)
{
        P=p;
        i=interest;
        n=num;
        B=P;
        yi=0;
        yp=0;
}
//finds and returns the monthly interest by multiplying the balance by the monthly interest
double Amortization::findMi(void)
{
        mi=B*i;
        return mi;
}
//Updates the balance by subtracting the monthly principal from the balance
void Amortization::updateB(void){B=B-mp;}
//returns the number of months payments are being made
int Amortization:: getN(void) {return n;}
//returns the balance
double Amortization::getB(void){return B;}
//finds and returns the monthly principal by subtracting the monthly interest from the monthly payment
double Amortization::findMp(void)
{
        mp=R-mi;
        return mp;
}
//computes and returns the monthly payment using the principal, monthly interest and number of months the loan is being paid
double Amortization::findR(void)
{
        R=P*i/(1-pow(1+i,-n));
        return R;
}
//Computes and returns the yearly interest by adding the monthly interest to the current value of the yearly interest
double Amortization::getYi(void){yi+=mi;}
//resets the yearly interest and yearly principal when a new year begins by setting both variables to 0
void Amortization:: resetYearly(void)
{
        yi=0;
        yp=0;
}
//computes and returns the yearly principal by adding the monthly principal to the current value of the yearly principal
double Amortization::getYp(void)
{
        yp+=mp;
        return yp;
}
 

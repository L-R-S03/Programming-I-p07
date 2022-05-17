#ifndef Amortization07_h
#define Amortization07_h 1
#include <iostream>
using namespace std;
class Amortization
{
        //variables to hold the values to be placed in the output file and needed for calculations
        double P,B,mi,mp,i,R,yi,yp;
        int n;
public:
        //empty constructor so a Amortization object can be made inside the Date constructor
        Amortization();
        //parameterized constructor that accepts the principal, monthly interest and the number of months
        Amortization(double p, double interest, int num);
        void resetYearly(void);
        double findMi(void);
        double findMp(void);
        double findR(void);
        double getB(void);
        int getN(void);
        void updateB(void);

        double getYi(void);
        double getYp(void);
};
#endif

#include <stdio.h>
#include <math.h>

double thr;
double mhr;
char sex;
double age;
double rhr;
char fit;
double fitval;

void calcthr ()
{
    double x;

    if (fit== 'L')
    {
        fitval= 0.55;
    }
    if (fit== 'M')
    {
        fitval= 0.65;
    }
    if (fit== 'H')
    {
        fitval= 0.80;
    }

    if (sex== 'M')
    {
        x= 0.033*(age-104.3);
        mhr= (203.7/(1+(exp(x))));
    }
    if (sex== 'F')
    {
        x= 0.0453*(age-107.5);
        mhr= (190.2/(1+(exp(x))));
    }
    
    thr= ((mhr-rhr)*fitval+rhr);
}

int main()
{
    printf ("Please enter your sex using either M or F: ");
        scanf (" %c", &sex);
    
    printf ("Please enter your age in a non-decimal number: ");
        scanf ("%lf", &age);
    
    printf ("Please enter your resting heart rate: ");
        scanf ("%lf", &rhr);
    
    printf ("Please enter your fitness level in either low (L), medium (M), or high (H): ");
        scanf (" %c", &fit);
    
    calcthr ();
    printf ("\nYour Training Heart Rate is %.0lf ",thr);
}


#include <stdio.h>
#include <math.h>

double weight;
double height;
double bodymassindex;

void BdMsIn ()
{
    bodymassindex= (weight/(height*height));

    if (bodymassindex < 18.5)
    {
        printf ("\nYour BMI is %.2lf, your classification is underweight.", bodymassindex);
    }

    if (bodymassindex >= 18.5 && bodymassindex <= 24.9)
    {
        printf ("\nYour BMI is %.2lf, your classification is normal.", bodymassindex);
    }

    if (bodymassindex >= 25 && bodymassindex <= 29.9)
    {
        printf ("\nYour BMI is %.2lf, your classification is overweight.", bodymassindex);
    }

    if (bodymassindex > 29.9)
    {
        printf ("\nYour BMI is %.2lf, your classification is obese.", bodymassindex);
    }

}

int main()
{
    printf ("Please enter your weight in kilograms: ");
        scanf ("%lf", &weight);
    
    printf ("Please enter your height in metres: ");
        scanf ("%lf", &height);

    BdMsIn ();
}


#include <stdio.h>
#include <math.h>

int main()
{
    int employeeNum;
    int numShifts;
    double baseWageRate;
    double hours = 0;
    double hourstotal= 0;
    double grosspay= 0;

    FILE*files;
    files = fopen ("L4_data.txt", "r");

        fscanf (files, "%d", &employeeNum);
        printf ("Employee Number: %d \n", employeeNum);

        fscanf (files, "%d", &numShifts);
        printf ("Number of Shifts: %d \n", numShifts);

        fscanf (files, "%lf", &baseWageRate);
        printf ("Base Wage Rate: %lf \n", baseWageRate);

            for (int j = 1; j <= numShifts; j++)
            {
            fscanf (files, "%d", &hours);
            hourstotal= (hourstotal + hours);
            grosspay= (baseWageRate*hourstotal);
            }
        printf ("Total Hours: %d \n", hourstotal);
        printf ("Grosspay: %lf \n", grosspay);
        
        hourstotal=0;
    
    fclose (files);
    return (0);

}


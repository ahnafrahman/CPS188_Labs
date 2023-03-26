#include <stdio.h>
#include <math.h>

int main()
{
    int lines=0;
    char c;
    int employeeNum;
    int numShifts;
    double baseWageRate;
    double hours = 0;
    double hourstotal= 0;
    double grosspay= 0;

    FILE*files;
    files = fopen ("L4_data.txt", "r");
    while ((c=fgetc (files)) != EOF)
    {
        if (c== '\n')
            {
            lines= (lines+1);
            }
    }
    fseek(files, 0, SEEK_SET);

    printf ("\n    Employee Number    Total Hours      Gross Pay \n\n");

    for (int i= 1; i<= lines; i++)
    {
        hourstotal=0;

        fscanf (files, "%d", &employeeNum);
        //printf ("Employee Number: %d \n", employeeNum);

        fscanf (files, "%d", &numShifts);
        //printf ("Number of Shifts: %d \n", numShifts);

        fscanf (files, "%lf", &baseWageRate);
        //printf ("Base Wage Rate: %.2lf \n\n", baseWageRate);

            for (int j = 1; j <= numShifts; j++)
            {
            fscanf (files, "%lf", &hours);
            hourstotal= (hourstotal + hours);
            }

        if (hourstotal <= 15)
        {
            grosspay= (hourstotal*baseWageRate);
        }

        if (hourstotal > 15&& hourstotal <= 25)
        {
            grosspay= ((hourstotal)*((baseWageRate*0.05) +baseWageRate));
        }

        if (hourstotal > 25)
        {
            grosspay= ((hourstotal)*((baseWageRate*0.10) +baseWageRate));
        }
        
        //printf ("Total Hours: %lf \n", hourstotal);
        
        //printf ("Grosspay: %.2lf \n\n", grosspay);
    
        printf (" \t %d \t\t %.2lf \t\t $%.2lf \n\n", employeeNum, hourstotal, grosspay);
    }        

    fclose (files);
    return (0);

}

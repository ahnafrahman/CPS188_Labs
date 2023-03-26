#include <stdio.h>
#include <math.h>

int rowPascal;
int counter1;

int main()
{
    printf ("\n");
    for(rowPascal= 1; rowPascal<= 9; rowPascal++)
    {
        counter1=1;

        for(int i= 1; i<= rowPascal; i++)
        {
            printf("%d ",counter1); 
            counter1 = (counter1 * (rowPascal-i))/i;
        }

        printf("\n");
    }

    printf ("\n");
    return 0;

}

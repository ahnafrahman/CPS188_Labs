#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Defining Headers
#include <conio.h> //For Warning Message

int mainMenu;
double speed; //Global Variables

void menu();
double calcMoon(double *minTime, double *maxTime);
double calcMars(double *minTime, double *maxTime);
double calcVenus(double *minTime, double *maxTime); //Declaring Functions

int main () 
{
    double minMoon, maxMoon, minMars, maxMars, minVenus, maxVenus;
    int exitProg; //Local Variables

    do 
    {
        system("CLS");
        menu();
        printf ("\n\nEnter a number corresponding to a trip of your choice. Enter 4 to exit the program.\n");
        scanf ("%d", &mainMenu);
        printf ("%d", mainMenu); //Takes User Input

        switch (mainMenu) //Switches menu for different cases
        {
            case 1: 
                system("CLS");
                printf ("Travel Time to the Moon\n"); //Displays Moon Calculation Instructions
                calcMoon(&minMoon, &maxMoon);
                printf ("\nTravelling at %.2lf km/h, it takes:\na minimum of %.2lf hours, \na maximum of %.2lf hours to get to the Moon. \n\n", speed, minMoon, maxMoon);
                printf ("Press any key to return to the main menu...");
                getch();
                break;

            case 2: 
                system("CLS");
                printf ("Travel Time to Mars\n"); //Displays Mars Calculation Instructions
                calcMars(&minMars, &maxMars);
                printf ("\nTravelling at %.2lf km/h, it takes:\na minimum of %.2lf hours, \na maximum of %.2lf hours to get to Mars. \n\n", speed, minMars, maxMars);
                printf ("Press any key to return to the main menu...");
                getch();
                break;

            case 3: 
                system("CLS");
                printf ("Travel Time to Venus\n");  //Displays Venus Calculation Instructions
                calcVenus(&minVenus, &maxVenus);
                printf ("\nTravelling at %.2lf km/h, it takes:\na minimum of %.2lf hours, \na maximum of %.2lf hours to get to Venus.\n\n", speed, minVenus, maxVenus);
                printf ("Press any key to return to the main menu...");
                getch();
                break;

            case 4: 
                exitProg = 1; //Variable to Exit Program
        }
    } while (exitProg != 1);
    return (0);
}

void menu() //Prints the main menu
{
    printf ("Space Travel Calculator\n");
    printf ("\n1- Traveling to the Moon");
    printf ("\n2- Traveling to Mars");
    printf ("\n3- Traveling to Venus");
    printf ("\n4- Exit Program");
}

double calcMoon(double *minTime, double *maxTime) //Calculates Moon Travel Time
{
    printf ("Enter travel speed in km/h: ");
    scanf ("%lf", &speed);
    *minTime = 363104/speed;
    *maxTime = 405696/speed;
}

double calcMars(double *minTime, double *maxTime) //Calculates Mars Travel Time
{
    printf ("Enter travel speed in km/h: ");
    scanf ("%lf", &speed);
    *minTime = 54600000/speed;
    *maxTime = 401000000/speed;
}

double calcVenus(double *minTime, double *maxTime) //Calculates Venus Travel Time
{
    printf ("Enter travel speed in km/h: ");
    scanf ("%lf", &speed);
    *minTime = 38000000/speed;
    *maxTime = 261000000/speed;
}
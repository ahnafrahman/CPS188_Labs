#include <stdio.h>
#include <math.h>

double quizA;
double quizB;
double quizC;
double quizD;
double quizE;
double quizF;
double quizG;
double quizH;
double quizI;
double quizJ;
double quizAverage;
double quizMark;
double quizGrade;

double midtermMark;
double midtermGrade;

double examMark;
double examGrade;

double finalGrade;


void calculateMark()
{
    if (quizA >= quizJ)
    {
        quizAverage = ((quizA + quizB + quizC + quizD + quizE + quizF + quizG + quizH + quizI)/9);    
    }
    if (quizJ > quizA)
    {
        quizAverage = ((quizB + quizC + quizD + quizE + quizF + quizG + quizH + quizI + quizJ)/9);
    }
    quizMark = (quizAverage/10); 
    quizGrade = (quizMark*25);

    if (midtermMark >= examMark)
    {
        midtermGrade= ((midtermMark/100)*35);
        examGrade= (examMark/100)*40;
    }
    if (midtermMark < examMark)
    {
        midtermGrade= ((midtermMark/100)*25);
        examGrade= (examMark/100)*50;
    }
    finalGrade= (quizGrade + midtermGrade + examGrade);
}

int main()
{
    printf ("Please enter your quiz 1 mark out of 10: ");
        scanf (" %lf", &quizA);

    printf ("Please enter your quiz 2 mark out of 10: ");
        scanf (" %lf", &quizB);

    printf ("Please enter your quiz 3 mark out of 10: ");
        scanf (" %lf", &quizC);

    printf ("Please enter your quiz 4 mark out of 10: ");
        scanf (" %lf", &quizD);

    printf ("Please enter your quiz 5 mark out of 10: ");
        scanf (" %lf", &quizE);

    printf ("Please enter your quiz 6 mark out of 10: ");
        scanf (" %lf", &quizF);

    printf ("Please enter your quiz 7 mark out of 10: ");
        scanf (" %lf", &quizG);

    printf ("Please enter your quiz 8 mark out of 10: ");
        scanf (" %lf", &quizH);

    printf ("Please enter your quiz 9 mark out of 10: ");
        scanf (" %lf", &quizI);

    printf ("Please enter your quiz 10 mark out of 10: ");
        scanf (" %lf", &quizJ);

    printf ("Please enter your midterm mark out of 100: ");
        scanf (" %lf", &midtermMark);

    printf ("Please enter your exam mark out of 100: ");
        scanf (" %lf", &examMark);

    calculateMark ();
    printf ("\nThe final grade you've achieved in this course is %.2lf%%. Good Work!", finalGrade);
    
}

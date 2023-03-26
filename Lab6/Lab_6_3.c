#include <stdio.h>
#define STACK_EMPTY '0'
#define STACK_SIZE 20

void
push(char stack[],    /* input/output - the stack */
     char item,       /* input - data being pushed onto the stack */
     int  *top,       /* input/output - pointer to top of stack */
     int  max_size)   /* input - maximum size of stack */
{
     if (*top < max_size-1) {
         ++(*top);
         stack[*top] = item;
     }
}

char
pop (char stack[],    /* input/output - the stack */
    int *top)        /* input/output - pointer to top of stack */
{
    char item;       /* value popped off the stack */

    if (*top >= 0) {
        item = stack[*top];
        --(*top);
    } else {
         item = STACK_EMPTY;
    }

    return (item);
}

int
main (void)
{
   char s [STACK_SIZE];
   int s_top = -1; // stack is empty

   char x, y, z;
   x = 'x';
   y = 'y';
   z = 'z';

    push(s, x, &s_top, STACK_SIZE);
    push(s, y, &s_top, STACK_SIZE);
    push(s, z, &s_top, STACK_SIZE);
    printf("Stack:\n");
    for(int i=s_top; i >= 0; i--)
    {
     printf("%c\n", s[i]);
    }

    pop(s, &s_top);
    printf("Updated stack:\n");
    for(int i=s_top; i >= 0; i--)
        {
         printf("%c\n", s[i]);
        }

   return (0);
}


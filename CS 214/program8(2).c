/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 8
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 03/31/24
 *
 * DOCUMENTATION
 * -------------
 *    This program will approximate PI based on the limit
 *    given by the user.
 *
 * PLEDGE
 * ------
 *    I pledge that all of the lines in this C program are my
 *    own first-time work for CS 214 this semester, that none
 *    of the lines in this C program have been copied from
 *    anyone or anywhere unless authorized to do so by my CS
 *    214 instructor, that I came up with the uploaded
 *    solution, that any help writing code was solely from my
 *    instructor, that I did not attempt to help any student
 *    on this assignment other than planning a solution, and
 *    that my violation of this pledge will result in my
 *    earning a score of zero on this work.
 *
 *    Signed: Christian T. Phan
 ************************************************************/
#include <stdio.h>
#include <math.h>

#define PROMPT_NUMBER "Please enter the limit: "

double calculatePI(int limit);

int main()
{
   // Local Declaration
   int inputNumber;
    
   // Statements
   printf("This program will approximate PI based\n");
   printf("on the limit given by the user.\n");
   printf(PROMPT_NUMBER);
   while (scanf("%d", &inputNumber) != 1)
   {
      printf("This is not an understanble number.\n");
      while (getchar() != '\n'); // Waits for new line
      printf("\n" PROMPT_NUMBER);
   }
   calculatePI(inputNumber);
   return 0;
}

// This function does the calculations for Pi
double calculatePI(int limit)
{
   // Local Declaration
   double counter,
          total = 0.0;
   // Statements
   for (counter = 1.0; counter <= limit; counter++)
   {
      total += 1.0 / (counter * counter);
      // Calculate PI based on page 310 of the textbook.
      printf("This is intergration %.0f.\n", counter);
      printf(" %f\n", sqrt(6 * total));
   }
   return 0;
}

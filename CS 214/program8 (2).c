/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 8
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 04/03/24
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
#include <stdlib.h>
#include <math.h>

#define MINIMUM_LIMIT 1
#define MAXIMUM_LIMIT 94906263

int getLimit(void);
double calculatePi(int limit);

int main()
{  
   // Local Declaration
   int limit;
   double piAproximation;

   // Statements
   printf("\nThis program will approximate PI based\n");
   printf("on the limit given by the user.\n");
   printf("Please enter a limit between %d and %d: \n", MINIMUM_LIMIT, MAXIMUM_LIMIT);
   
   limit = getLimit(); // Get limit from the user
   piAproximation = calculatePi(limit); // Calculates Pi with limit provided from user
   printf("\nPi with the limit of %d is about %f\n\n", limit, piAproximation);
   return 0;
}

// This function gets the limit as an input from the user, used to aproximate Pi
int getLimit(void)
{
   // Local Declaration
   int limit;
    
   // Statements
   while (scanf("%d", &limit) != 1 || limit < MINIMUM_LIMIT || limit > MAXIMUM_LIMIT)
   {
      printf("\nThis is not an understanble number.\n");
      while (getchar() != '\n'); // Waits for new line
      printf("Please enter a limit between %d and %d: \n", MINIMUM_LIMIT, MAXIMUM_LIMIT);
   }
   return limit;
}


// This function calculates and returns the approximated value of Pi
double calculatePi(int limit)
{
   // Local Declarations
   double count,
          total = 0.0;
   // Statements
   for (count = 1.0; count <= limit; count++)
      total += 1.0 / (count * count);
   // The textbook has this formula on page 310.
   return sqrt(6 * total);
}

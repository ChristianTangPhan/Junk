/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 3
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 02/12/2004
 *
 * DOCUMENTATION
 * -------------
 *    This program get 3 intergers from the user, displays 
 *    them vertically, then displays them again (vertically) 
      but in reverse order.
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

#define THREE_NUMBERS "%6d\n%6d\n%6d"
#define MAX_INPUT_AMOUNT 3

int main(void)
{
   int firstNumber,
       secondNumber,
       thirdNumber;
       
   printf("Please enter three intergers: ");
   if (scanf(THREE_NUMBERS, &firstNumber, &secondNumber, &thirdNumber) != MAX_INPUT_AMOUNT)
   {
      printf("You did not provide request values\n");
      perror("Runtime Error");
   }
   printf("Intergers top to bottom are:\n");
   printf(THREE_NUMBERS, firstNumber, secondNumber, thirdNumber);
   printf("\nIntergers bottom to top are:\n");
   printf(THREE_NUMBERS, thirdNumber, secondNumber, firstNumber);
   printf("\n");
   return 0;
}

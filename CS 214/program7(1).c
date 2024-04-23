/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 7
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 03/18/24
 *
 * DOCUMENTATION
 * -------------
 *    This program will analyze five numbers.
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

#define CHOICE_SMALLEST 'A'
#define CHOICE_LARGEST  'B'
#define CHOICE_SUM      'C'
#define CHOICE_AVERAGE  'D'
#define INPUT_AMOUNT    5
#define MENU_AMOUNT     1
#define SCANF_FORMAT    "%d %d %d %d %d"

char getMenuChoice(void);
int getSmallest(int numberA, int numberB, int numberC, int numberD, int numberE);
int getLargest(int numberA, int numberB, int numberC, int numberD, int numberE);
int getSum(int numberA, int numberB, int numberC, int numberD, int numberE);
float getAverage(int numberA, int numberB, int numberC, int numberD, int numberE);

int main(void)
{
   // Local Declarations
   int inputA, inputB, inputC, inputD, inputE;
   // Statements
   printf("This program will analyze five numbers.\n");
   printf("Please enter five numbers separated by whitespace:\n");
   if (scanf(SCANF_FORMAT, &inputA, &inputB, &inputC, &inputD, &inputE) != INPUT_AMOUNT)
   {
      printf("You did not enter five understandable numbers.\n");
      perror("Runtime Error");
      exit(EXIT_FAILURE);
   }
   switch (getMenuChoice())
   {
      case CHOICE_SMALLEST:
         printf("Smallest: %d.0\n", getSmallest(inputA, inputB, inputC, inputD, inputE));
         break;
      case CHOICE_LARGEST:
         printf("Largest: %d.0\n", getLargest(inputA, inputB, inputC, inputD, inputE));
         break;
      case CHOICE_SUM:
         printf("Sum: %d.0\n", getSum(inputA, inputB, inputC, inputD, inputE));
         break;
      case CHOICE_AVERAGE:
         printf("Average: %.1f\n", getAverage(inputA, inputB, inputC, inputD, inputE));
         break;
      default:
         printf("You did not enter a valid choices.\n");
         break;
   }
   return 0;
}

// This function gets the menu choice from the user.
char getMenuChoice(void)
{
   // Local Declarations
   char menuChoice;
   // Statements
   printf("Please enter a menu option using the character in parenthesis\n");
   printf("Find Smallest Number       (A)\n");
   printf("Find Largest Number        (B)\n");
   printf("Find Sum of all Numbers    (C)\n");
   printf("Find Average of all Number (D)\n");
   if (scanf(" %c", &menuChoice) != MENU_AMOUNT)
   {
      printf("You did not enter a valid choice.\n");
      perror("Runtime Error");
      exit(EXIT_FAILURE);
   }
   return menuChoice;
}

// This function find the smallest number of the 5 inputed.
int getSmallest(int numberA, int numberB, int numberC, int numberD, int numberE)
{
   // Local Declarations
   int smallestNumber;
   // Statements
   smallestNumber = numberA;
   if (numberB < smallestNumber)
      smallestNumber = numberB;
   if (numberC < smallestNumber)
      smallestNumber = numberC;
   if (numberD < smallestNumber)
      smallestNumber = numberD;
   if (numberE < smallestNumber)
      smallestNumber = numberE;
   return smallestNumber;
}

// This function find the largest number of the 5 inputed.
int getLargest(int numberA, int numberB, int numberC, int numberD, int numberE)
{
   // Local Declarations
   int largestNumber;
   // Statements
   largestNumber = numberA;
   if (numberB > largestNumber)
      largestNumber = numberB;
   if (numberC > largestNumber)
      largestNumber = numberC;
   if (numberD > largestNumber)
      largestNumber = numberD;
   if (numberE > largestNumber)
      largestNumber = numberE;
   return largestNumber;
}

// This function find the sum of the 5 inputed.
int getSum(int numberA, int numberB, int numberC, int numberD, int numberE)
{
   // Local Declarations
   int sum;
   // Statements
   sum = numberA + numberB + numberC + numberD + numberE;
   return sum;
}

// This function finds the average of the 5 inputed.
float getAverage(int numberA, int numberB, int numberC, int numberD, int numberE)
{
   // Local Declarations
   float average;
   // Statements
   average = (float)(numberA + numberB + numberC + numberD + numberE) / INPUT_AMOUNT;
   return average;
}
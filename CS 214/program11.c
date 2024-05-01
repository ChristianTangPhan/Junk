/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 11
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 04/28/2024
 *
 * DOCUMENTATION
 * -------------
 *    This program will analyze five numbers but uses arrays.
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
#include <stdbool.h>
#include <ctype.h>

#define MAX_CAPACITY 100
#define CHOICE_SMALLEST 'A'
#define CHOICE_LARGEST 'B'
#define CHOICE_SUM 'C'
#define CHOICE_AVERAGE 'D'

int getNumbers(int numbers[], int size);
void clearInput(void);
char getMenuChoice(void);
int getSmallest(int numbers[], int size);
int getLargest(int numbers[], int size);
int getSum(int numbers[], int size);
float getAverage(int numbers[], int size);

int main(void)
{
   // Local Declarations
   int numbers[MAX_CAPACITY];
   int size;
   // Statements
   printf("This program will analyze up to %d whole numbers.\n", MAX_CAPACITY);
   size = getNumbers(numbers, MAX_CAPACITY);
   if (size > 0)
      switch (getMenuChoice())
      {
         case CHOICE_SMALLEST:
            printf("Smallest: %d\n", getSmallest(numbers, size));
            break;
         case CHOICE_LARGEST:
            printf("Largest: %d\n", getLargest(numbers, size));
            break;
         case CHOICE_SUM:
            printf("Sum: %d\n", getSum(numbers, size));
            break;
         case CHOICE_AVERAGE:
            printf("Average: %f\n", getAverage(numbers, size));
            break;
         default:
            printf("You did not enter a valid choice.\n");
            break;
      }
   else
      printf("No numbers have been provided for analysis.\n");
   return 0;
}

// Display a menu, get the user's choice, and return it.
char getMenuChoice(void)
{
   // Local Declarations
   char menuChoice;
   // Statements
   printf("\n     M E N U\n");
   printf("=================\n");
   printf("(%c) Find Smallest\n", CHOICE_SMALLEST);
   printf("(%c) Find Largest\n", CHOICE_LARGEST);
   printf("(%c) Find Sum\n", CHOICE_SUM);
   printf("(%c) Find Average\n", CHOICE_AVERAGE);
   printf("=================\n");
   printf("Please enter a menu choice: ");
   if (scanf(" %c", &menuChoice) != 1)
   {
      printf("Your choice was not understood.\n");
      perror("Runtime Error");
      exit(EXIT_FAILURE);
   }
   return toupper(menuChoice);
}

// Receive an array and its maximum size,
// get and store values from user in array
// ad return the number of values entered.
int getNumbers(int numbers[], int size)
{
   // Local Declarations
   int index;
   // Statements
   printf("Please enter up to %d numbers and any non-number to stop sooner.\n", size);
   for (index = 0; index < size; index++)
   {
      printf("Value %d: ", index + 1);
      if (scanf("%d", &numbers[index]) != 1)
      {
         clearInput();
         break;
      }
   }
   return index;
}

// Clears screen
void clearInput(void)
{
   // Local Declarations
   int character;
   // Statements
   do
      character = getchar();
   while (character != '\n' && character != EOF);
}

// Searchs for the smallest numbers in an array and returns it.
int getSmallest(int numbers[], int size)
{
   // Local Declarations
   int smallest = numbers[0];
   // Statements
   for (int index = 1; index < size; index++)
      if (numbers[index] < numbers[index - 1])
         smallest = numbers[index];
   return smallest;
}

// Searchs for the largest numbers in an array and returns it.
int getLargest(int numbers[], int size)
{
   // Local Declarations
   int largest = numbers[0];
   // Statements
   for (int index = 1; index < size; index++)
      if (numbers[index] > numbers[index - 1])
         largest = numbers[index];
   return largest;
}

// Compute the arithmetic sum of numbers in an array and return it.
int getSum(int numbers[], int size)
{
   // Local Declarations
   int sum = numbers[0];
   // Statements
   for (int index = 1; index < size; index++)
      sum = sum + numbers[index];
   return sum;
}

// Compute the arithmetic mean of numbers in an array and return it.
float getAverage(int numbers[], int size)
{
   // Statements
   return getSum(numbers, size) / (float)size;
}
/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 4
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 02/26/2024
 *
 * DOCUMENTATION
 * -------------
 *  
 *    This program gets an input in inches from the user
 *    to convert into centimeters, feet, meters, and yards.
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

#define CENTIMETERS_PER_INCH 2.54f
#define INCHES_PER_FEET 12.0f
#define INCHES_PER_METER 39.37f
#define INCHES_PER_YARD 3.0f
#define MAX_INPUT_AMOUNT 1

int main(void)
{
   float inches,
         feet,
         yards,
         centimeters,
         meters;
	
	printf("\nPlease enter inches: ");
   if (scanf("%f", &inches) != MAX_INPUT_AMOUNT)
   {
      printf("You did not provide a number\n");
      perror("Runtime Error");
   }
   else
   {
      feet = inches / INCHES_PER_FEET;
      yards = inches / INCHES_PER_YARD;
      centimeters = inches * CENTIMETERS_PER_INCH;
      meters = inches / INCHES_PER_METER;
        
      printf("\n~Conversions~\n"); 
      printf("Centimeters: %f\n", centimeters); 
      printf("       Feet: %f\n", feet);
      printf("     Meters: %f\n", meters);
      printf("      Yards: %f\n", yards);
      return 0;
   }
}


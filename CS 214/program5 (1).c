/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 5
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 03/04/2024
 *
 * DOCUMENTATION
 * -------------
 *    This program converts degrees in fahrenheit to celcius
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

#define MAX_INPUT_AMOUNT 1

double convertFahrenheitToCelcius(double inputFahrenheit);

int main(void)
{
   double inputFahrenheit,
          outputCelcius;
          
   printf("This program converts inputed degrees\n");    
   printf("(in fahrenheit) to celcius!!\n");    
   printf("Please enter degrees in Fahrenheit: ");
   if (scanf("%lf", &inputFahrenheit) != MAX_INPUT_AMOUNT)
   {
      printf("Please enter a reasonable Fahrenheit measurement.\n");
      perror("Runtime Error");
   }
   else
   {
      outputCelcius = convertFahrenheitToCelcius(inputFahrenheit);
      printf("Celcius: %f \n", outputCelcius);
      return 0;
   }
}

double convertFahrenheitToCelcius(double inputFahrenheit)
{
   return (100.0 / 180.0) * (inputFahrenheit - 32);
}

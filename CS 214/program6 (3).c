/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 6
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 03/11/2024
 *
 * DOCUMENTATION
 * -------------
 *    This program will generate a payroll earnings statement.
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

float getCommission(float sales);
float getGrossPay(float commission, float bonus);
float getFederalWithholding(float grossPay);
float getStateWithholding(float grossPay);
float getRetirementPlan(float grossPay);
float getTotalWithholding(float federal, float state, float retirement);
float getNetPay(float grossPay, float totalWithholding);

int main(void)
{
   // Local Declarations
   float bonus,
         commission,
         federal,
         grossPay,
         netPay,
         sales, 
         state,
         retirement,
         totalWithholding;
            
   // Statements
   //    Get Input
   printf("This program will generate a payroll earnings statement.\n");
   printf("Please enter sales: ");
   if (scanf("%f", &sales) != MAX_INPUT_AMOUNT)
   {
      printf("Please enter a reasonable sales amount.\n");
      perror("Runtime Error");
   }
   printf("Please enter bonus: ");
   if (scanf("%f", &bonus) != MAX_INPUT_AMOUNT)
   {
      printf("Please enter a reasonable bonus amount.\n");
      perror("Runtime Error");
   }

   //    Perform Calculations
   commission       = getCommission(sales);
   grossPay         = getGrossPay(commission, bonus);
   federal          = getFederalWithholding(grossPay);
   state            = getStateWithholding(grossPay);
   retirement       = getRetirementPlan(grossPay);
   totalWithholding = getTotalWithholding(federal, state, retirement);
   netPay           = getNetPay(grossPay, totalWithholding);

   //    Display Output
   printf("\n      Arctic Ice Company       ");
   printf("\n      Earnings Statement       ");
   printf("\n============================== ");
   printf("\nSales:               $%5.2f    ", sales);
   printf("\nBonus:               $%5.2f    ", bonus);
   printf("\n------------------------------ ");
   printf("\nCommission:          $%5.2f    ", commission);
   printf("\nGross Pay:           $%5.2f    ", grossPay);
   printf("\n------------------------------ ");
   printf("\nFederal Withholding: $%5.2f    ", federal);
   printf("\nState Withholding:   $%5.2f    ", state);
   printf("\nRetirement Plan:     $%5.2f    ", retirement);
   printf("\nTotal Withholding:   $%5.2f    ", totalWithholding);
   printf("\n------------------------------ ");
   printf("\nNet Pay:             $%5.2f    \n", netPay);

}

float getCommission(float sales)
{
   return sales * .125;
}

float getGrossPay(float commission, float bonus)
{
   return commission + bonus;
}

float getFederalWithholding(float grossPay)
{
   return grossPay * .25;
}

float getStateWithholding(float grossPay)
{
   return grossPay * .10;
}

float getRetirementPlan(float grossPay)
{
   return grossPay * .08;
}

float getTotalWithholding(float federal, float state, float retirement)
{
   return federal + state + retirement;
}

float getNetPay(float grossPay, float totalWithholding)
{
   return grossPay - totalWithholding;
}

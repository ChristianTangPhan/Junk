/**********************************************************************/
/*                                                                    */
/* Program Name: program4 -       */
/* Author:       Christian Phan                                       */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 4, 2024                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge this assignment is my own first time work.                */
/* I pledge I did not copy or try to copy any code from the Internet. */
/* I pledge I did not copy or try to copy any code from anyone else.  */
/* I pledge I did not attempt to give code to anyone else on this.    */
/* I understand if I violate this pledge I will receive a 0 grade.    */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */ 
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program will create and sum a database of experimental        */
/* scientific data.                                                   */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define COURSE_NUMBER    "CS227" /* PCC asssigned course number       */
#define PROGRAM_NUMBER   4       /* Teacher assignment program number */
#define PROGRAMMER_NAME  "Phan"  /* The programmer's last name        */
#define DATA_ALLOC_ERR   1       /* Data allocation error             */
#define END_OF_STRING    '\0'    /* Mi          */
#define MAX_CUSTOMERS    100     /* Ma          */
#define MAX_NAME_LENGTH  20      /* Mi           */
#define MIN_CUSTOMERS    2       /* Ma          */
#define QUIT             0       /* Qu                     */

/**********************************************************************/
/*                          Customer Record                           */
/**********************************************************************/
/* A customer record */
struct customer
{
    char last_name[MAX_NAME_LENGTH];
   float amount;
     int priority;
};

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the instructions                                          */
int get_numbers_customers();
   /* Get the quantity/amount of data values                          */
void get_customers(struct customer *p_customers_start, int number_of_customers);
   /* Get the experimental scientific data                            */
void clean_up_names(struct customer *p_customers_start, int number_of_customers);
   /* Sort the experimental scientific data                           */
void sort_customers(struct customer *p_customers_start, int number_of_customers);
   /* Print the experimental scientific data                          */
void print_customers(struct customer *p_customers_start, int number_of_customers);
   /* Sum the experimental scientific data                            */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   struct customer *p_customers_start;        /* Pointer to where customer data starts          */
      int number_of_customers; /* Amount of data values                 */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop summing experimental scientific data until user quits      */
   while (print_instructions(),
         (number_of_customers = get_numbers_customers()) != QUIT)
   {
      /* Allocate memory for accounts receivable database and abort   */
      /* if unavaiable                                                */
      if ((p_customers_start = (struct customer*)malloc(sizeof(*p_customers_start) 
         * number_of_customers)) == NULL)
      {
         printf("\nError %d occurred in function main().",
                                                        DATA_ALLOC_ERR);
         printf("\nMemory was not allocatable.");
         printf("\nThe program is aborting.");
         exit  (DATA_ALLOC_ERR);
      }

      /* Get and process experimental scientific data                */
      get_customers  (p_customers_start, number_of_customers);
      clean_up_names (p_customers_start, number_of_customers);
      sort_customers (p_customers_start, number_of_customers);
      print_customers(p_customers_start, number_of_customers);

      /* Note that the customer database has been processed           */
      printf("\n\n******* End Of Customer Database Processing *******\n");

      /* Free the data allocated in memory                           */   
      free (p_customers_start);
       

   }

   /* Print a goodbye message and terminate the program               */
   printf("\nThank you for processing numbers. Have a nice day! :>");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER   );
   printf("\n                Programmer: %s",        PROGRAMMER_NAME  );
   printf("\n                PCC Course Number: %s", COURSE_NUMBER    );
   printf("\n========================================================");

   return;
}

/**********************************************************************/
/*                       Print the instructions                       */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program allows you to input customers which owe"    );
   printf("\nyou money (your accounts receivable), and manage these"  );
   printf("\naccounts in a database.  You will enter the following:"  );
   printf("\n   customers last name (1-20 characters)"                    );
   printf("\n   Amount the customers owes (to the exact cent)"            );
   printf("\n   customers priority (1=VIP, 2=Important, 3=Regular)"       );
   printf("\nFrom 2 to 100 customers may be processed."               );

   return;
}

/**********************************************************************/
/*             Ask for the quantity/amount of data values             */
/**********************************************************************/
int get_numbers_customers()
{
   int number_of_customers; /* Amount of customers                    */
   
   do 
   {
      printf("\n\nGet the customers for the database"                 );
      printf(  "\n--------------------------------------------------" );
      printf(  "\nHow many customers do you have (2 to 100, 0=quit): ");
      scanf ("%d", &number_of_customers);
   } 
   while ((number_of_customers < MIN_CUSTOMERS || 
           number_of_customers > MAX_CUSTOMERS) && 
           number_of_customers != QUIT);

   return number_of_customers; 
}

/**********************************************************************/
/* Collect experimental scientific data (flip negatives to positives) */
/**********************************************************************/
void get_customers(struct customer *p_customers_start, int number_of_customers)
{

   struct customer *p_customers; /* Pointer to experimental scientific data          */

   for (p_customers = p_customers_start; 
       (p_customers - p_customers_start) < number_of_customers;
        p_customers++)
   {
      printf(  "Customer Number %d:", 
         (int) (p_customers - p_customers_start) + 1);
      printf("\n   Enter the customer's last name: ");
      scanf ("%s", &p_customers->last_name);
      printf(  "   Enter the amount owed: ");
      scanf ("%f", &p_customers->amount);
      printf(  "   Enter the customer's priority (1-3): ");
      scanf ("%d", &p_customers->priority);
   }
   
   return;
}

/**********************************************************************/
/*        Sort experimental scientific data in decending order        */
/**********************************************************************/
void clean_up_names(struct customer *p_customers_start, int number_of_customers)
{
   struct customer *p_customers; /* Pointer to experimental scientific data          */
   char *p_fast = p_customers->last_name,
        *p_slow = p_customers->last_name;
        
   for (p_customers = p_customers_start; 
       (p_customers - p_customers_start) < number_of_customers;
        p_customers++)
   {
      while (*p_fast != END_OF_STRING)
      {
          printf("enter while");
         if (!isalpha(*p_fast))
            *p_slow++ = tolower(*p_fast);
         p_fast++;
      }

      *p_slow = END_OF_STRING;
   }

   return;
}

/**********************************************************************/
/*     Print the experimental scientific data and mark duplicates     */
/**********************************************************************/
void sort_customers(struct customer *p_customers_start, int number_of_customers)
{
   /*struct customer *p_customers,
                   *temp_customer; 
      int          counter;

   for (counter = 1; counter <= number_of_customers; counter++)
   {
      printf("\ndoing outer loop");
      for (p_customers = p_customers_start; 
          (p_customers - p_customers_start) <= (number_of_customers - counter); 
           p_customers++)
           printf("%d counter", (int) (p_customers - p_customers_start));
           printf("%d condition", (number_of_customers - counter));
      {
         printf("\ndoing inner loop\n");
         if (strcmp(p_customers->last_name, ((p_customers + 1)->last_name)) < 0)
         {
            printf("%d counter", (int) (p_customers - p_customers_start));
            printf("%d condition", (number_of_customers - counter));
            printf("%s customer", (p_customers+1)->last_name);
            temp_customer     = p_customers;
            p_customers       = (p_customers - 1);
         }
      }
   }*/

   return;
}

/**********************************************************************/
/*                          Print the total                           */
/**********************************************************************/
void print_customers(struct customer *p_customers_start, int number_of_customers)
{
   struct customer *p_customers; /* Pointer to experimental scientific data          */
   
   printf("\n  Here is the accounts receivable customer database"     );
   printf("\n====================================================="   );
   printf("\n   Customer Name         Amount        Priority"         );
   printf("\n--------------------    ---------    -------------"      );
   
   for (p_customers = p_customers_start; 
       (p_customers - p_customers_start) < number_of_customers;
        p_customers++)
   {
      printf("\n%s $%20.2f %d",
         p_customers->last_name, p_customers->amount, p_customers->priority);
      switch (p_customers->priority)
      {
         case 1:
            printf(" (VIP)");
            break;

         case 2:
            printf(" (High)");
            break;

         case 3:
            printf(" (Normal)");
      }
   }

	return;
}
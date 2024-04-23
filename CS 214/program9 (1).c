#include <stdio.h>
#include <stdlib.h>

#define MENU_STRING "    M E N U\n1.  Pattern One\n2.  Pattern Two\n3. Pattern Three\n4.  Pattern Four\n.  Quit\n"

void patternOne(int size);
void patternTwo(int size);
void patternThree(int size);
void patternFour(int size);
int  getOption();
int  getSize();

int main()
{
   // Local Declarations
   int option, size;
   // Statements
   printf("instructions\n");
   do
   {
      option = getOption();
      switch (option)
      {
      case 1:
         size = getSize();
         patternOne(size);
         break;
      case 2:
         size = getSize();
         patternTwo(size);
         break;
      case 3:
         size = getSize();
         patternThree(size);
      case 4:
         size = getSize();
         patternFour(size);
         break;
      case 5:
         printf("\nThank you for using this program!\n");
         break;
      default:
         printf("\nThis is not an option.\n");
         break;
      }
   }
   while (option != 5);
   return 0;
}
int getOption()
{
   int option;
   printf(MENU_STRING);
   printf("Please enter an option: ");
   while (scanf("%d", &option) != 1)
   {
      printf("\nThis is not an option.\n");
      while (getchar() != '\n'); // Waits for new line
      printf(MENU_STRING);
      printf("Please enter an option");
   }
    return option;
}

int getSize()
{
   int size;
   printf("Please enter a size: ");
   while (scanf("%d", &size) != 1)
   {
      printf("\nThis is not an understanble size.\n");
      while (getchar() != '\n'); // Waits for new line
      printf("Please enter a size: ");
   }
    return size;
}

void patternOne(int size)
{
   // Local Declarations
   int row, column;
   // Statements
   for (row = 1; row <= size; row++)
   {
      for (column = 1; column <= size; column++)
      {
         if (row == column)
            printf("%d", size);
         else
            printf("$");
      }
      printf("\n");
   }
}

void patternTwo(int size)
{
   // Local Declarations
   int row, column;
   // Statements
   for (row = 1; row <= size; row++)
   {
      for (column = 1; column <= size; column++)
      {
         if (row == size + 1 - column)
            printf("%d", size);
         else
            printf("$");
      }
      printf("\n");
   }
}

void patternThree(int size)
{
   // Local Declarations
   int row, column;
   // Statements
   for (row = 1; row <= size; row++)
   {
      for (column = 1; column <= size; column++)
      {
         if (row > size + 1 - column)
            printf("%d", size);
         else
            printf("$");
      }
      printf("\n");
   }
}

void patternFour(int size)
{
   // Local Declarations
   int row, column;
   // Statements
   for (row = 1; row <= size; row++)
   {
      for (column = 1; column <= size; column++)
      {
         if (row > column)
            printf("%d", size);
         else
            printf("$");
      }
      printf("\n");
   }
}

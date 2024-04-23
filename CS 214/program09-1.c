/* ===========================================================================
* Class Information
* ------------------  ------------------------------------------------------
*      Program Name:  program09
*   Programmer Name:  Neinas, Jeremy
*        Student ID:  150486
* Instructor/Course:  Mr. Plain CS 214-3, C Programming
*  Program Due Date:  4/18/2024
*
* Documentation
* --------------------------------------------------------------------------
*  This program will count certain things from reading a file
* ========================================================================= */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define COUNT_ALL       5
#define COUNT_CHARS     3
#define COUNT_LINES     1
#define COUNT_SENTENCES 4
#define COUNT_WORDS     2
#define QUIT            6

void printInstructions();
void printMenu        ();
int  getMenuChoice    ();
int  processFile      (int choice);
void printResult      (int choice, int result);
void printGoodbye     ();

int main()
{
   int menuChoice;
  
   printInstructions();
   printMenu();
  
   menuChoice = getMenuChoice();
   
   while(menuChoice != QUIT)
   {
      switch (menuChoice)
      {
         case COUNT_LINES:
         case COUNT_WORDS:
         case COUNT_CHARS:
         case COUNT_SENTENCES:
            printResult(menuChoice, processFile(menuChoice));
            break;
         case COUNT_ALL:
            printResult(COUNT_LINES,     processFile(COUNT_LINES));
            printResult(COUNT_WORDS,     processFile(COUNT_WORDS));
            printResult(COUNT_CHARS,     processFile(COUNT_CHARS));
            printResult(COUNT_SENTENCES, processFile(COUNT_SENTENCES));
            break;  
         default:
            printf("Unknown choice.");
            break;
      }
      printMenu();
      menuChoice = getMenuChoice();
   }
  
   printGoodbye();
  
   return 0;
}


void printInstructions()
{
   printf("This program will count certain things from a\n"); 
   printf("file based on your choice");
   
   return;
}

void printMenu()
{
   printf("\nMenu:");
   printf("\n-------------------------------------");
   printf("\n %d - Count Lines", COUNT_LINES);
   printf("\n %d - Count Words", COUNT_WORDS);
   printf("\n %d - Count Characters", COUNT_CHARS);
   printf("\n %d - Count Sentences", COUNT_SENTENCES);
   printf("\n %d - Count All", COUNT_ALL);
   printf("\n %d - Quit", QUIT);
   
   return;
}

int getMenuChoice()
{
   int menuChoice;
   
   do
   {
      printf("Please enter a valid Menu choice");
      scanf("%d", &menuChoice);
      
   }while (menuChoice < COUNT_LINES || menuChoice > QUIT);
   
   return menuChoice;
}

int processFile (int choice)
{
   int count = 0;
   int currentChar;
   
   FILE *fileIn;
   
   fileIn = fopen("input09.txt", "r");
   
   if ("input09.txt" ==  NULL)
   {
      printf("This file does not exist");
   }
   else
   {
      while((currentChar = fgetc(fileIn)) != EOF)
      {
         switch(getMenuChoice())
         {
            case COUNT_CHARS:                     
            
               if (currentChar != '\n')
               {
                  count++;
               }
               else
               {
                  fclose(fileIn);
               } 
               return count;
               break;
         }
      }
   }
return count;
}
   
void printResult      (int choice, int result)
{
  printf("it compiled");
}       
 

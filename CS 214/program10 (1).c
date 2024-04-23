/*************************************************************
 * CLASS INFORMATION
 * -----------------
 *      Program Name: Program 10
 *   Programmer Name: Christian T. Phan
 *        Student ID: 150311
 * Instructor/Course: Mr. Chappell for CS 214-2, C Programming
 *  Program Due Date: 04/18/2024
 *
 * DOCUMENTATION
 * -------------
 *    This program counts the characters in a text file and 
 *    prints out the amount of each.
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
#include <ctype.h>

#define CHAR_TYPES 5
#define INPUT_FILE "pg30.txt"
#define INDEX_ALPHA 0
#define INDEX_DIGIT 1
#define INDEX_PUNCT 2
#define INDEX_SPACE 3
#define INDEX_OTHER 4

FILE *openFile(void);
void processFile(FILE *inputFile, int counts[]);
void closeFile(FILE *inputFile);
void displayReport(int counts[]);
void die(char *action);

int main(void)
{
   // Local Declarations
   FILE *inputFile;
   int counts[CHAR_TYPES] = {0};
   // Statements
   inputFile = openFile();
   processFile(inputFile, counts);
   closeFile(inputFile);
   displayReport(counts);
   return 0;
}

// This function opens a file containing a reference to the KJV Bible
FILE *openFile(void)
{
   // Local Declarations
   FILE *inputFile = fopen(INPUT_FILE, "r");
   // Statements
   if (inputFile == NULL) 
   {
      die("opened");
   }
   return inputFile;
}

// This function counts the characters in the file and adds one to its designated catergory in the count array
void processFile(FILE *inputFile, int counts[])
{
   // Local Declarations
   int text;
   // Statements
   while ((text = fgetc(inputFile)) != EOF) 
   {
      if (isalpha(text))
         counts[INDEX_ALPHA]++;
      else if (isdigit(text))
         counts[INDEX_DIGIT]++;
      else if (ispunct(text))
         counts[INDEX_PUNCT]++;
      else if (isspace(text))
         counts[INDEX_SPACE]++;
      else
         counts[INDEX_OTHER]++;
   }
}

// This function closes the file after reading
void closeFile(FILE *inputFile)
{
   if (fclose(inputFile) == EOF) 
   {
      die("closed");
   }
}

// This function lets the user know if there were any file errors
void die(char *action)
{
   // Statements
   fprintf(stderr, "%s could not be %s.\n", INPUT_FILE, action);
   perror("Runtime Error");
   exit(EXIT_FAILURE);
}

// This function displays the count of characters in their categories
void displayReport(int counts[])
{
   // Local Declarations
   int index;
   char *labels[CHAR_TYPES] = {
      "Alpha",
      "Digit",
      "Punct",
      "Space",
      "Other"
   };
   // Statements
   for (index = 0; index < CHAR_TYPES; index++)
   {
      printf("%s Characters: %d\n", labels[index], counts[index]);
   }
}

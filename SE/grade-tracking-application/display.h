#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants for menu options
const char *MENU_ADD    = "Add Assignment";
const char *MENU_VIEW   = "View Assignments";
const char *MENU_UPDATE = "Update Assignment";
const char *MENU_DELETE = "Delete Assignment";
const char *MENU_EXIT   = "Exit Application";

// Function prototypes
void display_heading();
void display_menu   ();

// Displays the app heading
void display_heading()
{
    printf("=========================================================================================\n");
    printf("                         Student Grade Tracking Application                              \n");
    printf("=========================================================================================\n\n");
    printf("Welcome student!\n");
    printf("This application helps you track your grades effectively.\n");
    return;
}

// Display the main menu
void display_menu()
{
        printf("\n\n\n-------------------------------  MENU -------------------------------\n");
        printf(" [1] -> %s\n", MENU_ADD);
        printf(" [2] -> %s\n", MENU_VIEW);
        printf(" [3] -> %s\n", MENU_UPDATE);
        printf(" [4] -> %s\n", MENU_DELETE);
        printf(" [5] -> %s\n", MENU_EXIT);
        printf("---------------------------------------------------------------------\n");
        return;
}

// Display add assignment header
void display_add_header()
{
    printf("\n\n\n\n------------------------ Add Assignment --------------------------\n");
    return;
}

void display_add_menu()
{
    printf("\n----------- Select -----------\n");
    printf(" [1] -> Add another assignment\n");
    printf(" [2] -> Return to main menu\n");
    printf("------------------------------\n");
    return;
}
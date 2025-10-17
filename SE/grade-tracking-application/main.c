#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "display.h"
#include "assignment.h"

int main()
{
    // Menu choices
    int        choice;
    char       assign_choice;
    // Assignment List
    ASSIGNMENT *assignment_list = NULL;

    assignment_list = file_load();
    
    do
    {
        // Get the user's menu choice
        display_menu();
        printf("\nPlease select an option: ");
        scanf("%d", &choice);

        // Handle menu choice
        switch (choice)
        {
        // Add Assignment
        case 1:
            display_add_header();
            do
            {
                add_assignment(&assignment_list);
                display_add_menu();
                scanf ("%d", &choice);
            } while (choice != 2);
            break;
            
        // View Assignments
        case 2:
            printf("View Assignments selected.\n");
            /*
            printf("Do you want to view all your assignments: [Y or N]:");
            scanf (" %c", &assign_choice);
            assign_choice = tolower(assign_choice);
            if (assign_choice == 'y')
                display_assignments(assignment_list);
            printf("Please select the assignment to view: ");*/
            display_assignments(assignment_list);
            break;
            
        // Update Assignment
        case 3:
         printf("Update Assignment selected.\n");
         edit_assignment(assignment_list);
         break;

            
        // Delete Assignment
        case 4:
            printf("Delete Assignment selected.\n");
            // function to delete Assignment
            reassign_ids(assignment_list);
            break;
            
        // Exit Application
        case 5:
            // file_save(assignment_list);
            file_save(assignment_list);
            assignment_list = NULL;
            free_assignments(&assignment_list);
            printf("Exiting the application. Goodbye!\n");
            return 0;
            
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

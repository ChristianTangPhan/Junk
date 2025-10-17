#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Symbolic constants
#define FILE_NAME           "assignments.csv"
#define title_length        100
#define ALLOC_ERROR         1
#define NO_CSV              2

// Struct definition
struct assignment
{
   char  title[100];
   float points_earned,
         total_possible_points;
   int   assignment_id;

   struct assignment *p_next;
};
typedef struct assignment ASSIGNMENT;

// Function prototypes
void  get_assignment_title     (char *title, size_t size);
float get_earned_points        (float possible_pts);
float get_possible_points      ();
void  display_assignments      (ASSIGNMENT  *p_assignment_list);
void  reassign_ids             (ASSIGNMENT *p_assignment_list);
void  delete_assignment        (ASSIGNMENT **p_assignment_list);
void  sort_assignments_by_id   (ASSIGNMENT *first_node);
void  edit_assignment          (ASSIGNMENT *p_assignment_list);
void  file_save (ASSIGNMENT *p_assignment_list);
void  file_clear();
ASSIGNMENT *file_load            ();
ASSIGNMENT *insert_assignment    (ASSIGNMENT *p_assignment_list,    int   id,            char *p_title, 
                                    float      total_possible_points, float points_earned);

// Adds a new assignment to the list
void add_assignment(ASSIGNMENT **p_assignment_list)
{
   // Automatic ID counter
   static int next_id = 1;

   // Sets max id for an already existing list
   if (*p_assignment_list != NULL && next_id == 1)
   {
      ASSIGNMENT *temp = *p_assignment_list;
      int max_id = 0;
      while (temp != NULL)
      {
         if (temp->assignment_id > max_id)
            max_id = temp->assignment_id;
         temp = temp->p_next;
      }
      next_id = max_id + 1;
   }

   ASSIGNMENT *p_new_assignment,
	           *p_temp;

   // Creates a new assignment
   if ((p_new_assignment = (ASSIGNMENT*) malloc(sizeof(ASSIGNMENT))) == NULL)
   {
      printf("\nError occurred in insert_assigments.");
      printf("\nCannot allocate memory for the new student record.");
      printf("\nThe program is aborting.");
      return;
   }

   // Add Assignment Data
   get_assignment_title(p_new_assignment->title, sizeof(p_new_assignment->title));
   p_new_assignment->total_possible_points = get_possible_points();
   p_new_assignment->points_earned         = get_earned_points(p_new_assignment->total_possible_points);
   p_new_assignment->assignment_id         = next_id++;

   // Check for first assignment
   if (*p_assignment_list == NULL)
   {
      *p_assignment_list = p_new_assignment;
   }
   else
   {
      // Add assignment to the end of a current list
      p_temp = *p_assignment_list;
      while (p_temp->p_next != NULL)
      {
         p_temp = p_temp->p_next;
      }
      p_temp->p_next = p_new_assignment;
   }
   p_new_assignment->p_next = NULL;
   return;
}

// Get and validate the assignment title input
void get_assignment_title(char *title, size_t size)
{
    int c;
    // Clear leftover input from previous scanf
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nEnter assignment title: ");
    fgets(title, size, stdin);

    // Remove trailing newline
    title[strcspn(title, "\n")] = '\0';
}

// Get and validate possible points input
float get_possible_points()
{
    char c;
    float possible;

    while (1)
    {
        printf("\nEnter points possible: ");

        // Validate numeric input
        if (scanf("%f", &possible) != 1)
        {
            printf("Invalid input. Enter a number.\n");
            // clear input buffer
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Validate non-negative input
        if (possible < 0)
        {
            printf("Points possible cannot be negative.\n");
            continue;
        }

        // Input is valid
        break;
    }
    return possible;
}

// Get and validate earned points input
float get_earned_points(float possible_pts)
{
   char  c;
   float earned;
   while (1)
   {  
      printf("\nEnter points earned: ");
      if (scanf("%f", &earned) != 1)
      {
         printf("Invalid input. Enter a number.\n");
         // clear input buffer
         while ((c = getchar()) != '\n' && c != EOF);
         continue;
      }
      if (earned < 0)
      {
        printf("Points earned cannot be negative.\n");
        continue;
      }
      
		// Compares points earned with total possible points, 
	   if (earned > possible_pts)
	   { 
		   printf("\nYou can not earn more points that the max points for the assignment.\n");
		   continue;
		}
      break;
   }
   return earned;
}

// Display all assignments in the list
void display_assignments(ASSIGNMENT *p_assignment_list)
{
    if (p_assignment_list == NULL)
    {
        printf("\nNo assignments to display.\n");
        return;
    }

    printf("\n===== Assignment List =====\n");
    while (p_assignment_list != NULL)
    {
        printf("\n  Assignment ID: %d",   p_assignment_list->assignment_id);
        printf("\n          Title: %s",   p_assignment_list->title);
        printf("\n  Points Earned: %.2f", p_assignment_list->points_earned);
        printf("\nPoints Possible: %.2f", p_assignment_list->total_possible_points);
		
		//Calculate and Print the percentage
		printf("\n    Percentage:  %.2f%%", p_assignment_list->points_earned /
		                                     p_assignment_list->total_possible_points * 100.0f);

        printf("\n---------------------------\n");

        // Move to the next node
        p_assignment_list = p_assignment_list->p_next;
    }
}

// Free all assignments in the list
void free_assignments(ASSIGNMENT **p_assignment_list) 
{
    ASSIGNMENT *p_current = *p_assignment_list;
    while (p_current != NULL) 
    {
        ASSIGNMENT *p_next = p_current->p_next;
        free(p_current);
        p_current = p_next;
    }
    *p_assignment_list = NULL; // Reset the head pointer
}

// Re-assign all assignment IDs in order from 1 to N
void reassign_ids(ASSIGNMENT *p_assignment_list)
{
   // No assignments yet
    if (p_assignment_list == NULL)
    {
        printf("\nNo assignments, cannot re-assign IDs.\n");
        return;
    }

    // Assign ids from 1 to N
    int id_counter = 1;
    ASSIGNMENT *current = p_assignment_list;

    while (current != NULL)
    {
        current->assignment_id = id_counter++;
        current = current->p_next;
    }
}

void delete_assignment(ASSIGNMENT **p_assignment_list) 
{
    if (*p_assignment_list == NULL) {
        printf("\nNo assignments to delete.\n");
        return;
    }
    
    printf("\n--- DELETE ASSIGNMENT ---\nEnter assignment ID to delete: ");
    int id;
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }

    ASSIGNMENT *current = *p_assignment_list;
    ASSIGNMENT *previous = NULL;

    // find the node
    while (current != NULL && current->assignment_id != id) {
        previous = current;
        current = current->p_next;
    }

    // not found
    if (current == NULL) {
        printf("Assignment with ID %d not found.\n", id);
        return;
    }

    // confirm delete
    printf("Delete '%s'? (y/n): ", current->title);
    char confirm;
    scanf(" %c", &confirm);  // leading space skips whitespace

    if (confirm == 'y' || confirm == 'Y') {
        if (previous == NULL)
            *p_assignment_list = current->p_next;  // deleting head
        else
            previous->p_next = current->p_next;    // deleting middle/end

        free(current);
        printf("Assignment deleted!\n");
    } 
    else {
        printf("Deletion cancelled.\n");
    }
}


void sort_assignments_by_id(ASSIGNMENT *first_node) 
{
    if (first_node == NULL) 
        return;

    int swapped; 
    ASSIGNMENT *ptr; 
    ASSIGNMENT *last = NULL; 

    do 
    {
        swapped = 0;
        ptr = first_node;

        while (ptr->p_next != last) 
        {
            if (strcmp(ptr->title, ptr->p_next->title) > 0) 
            {
                char  temp_title[100];
                float temp_earned, temp_possible;
                int   temp_id;

                strcpy(temp_title, ptr->title);
                temp_earned   = ptr->points_earned;
                temp_possible = ptr->total_possible_points;
                temp_id       = ptr->assignment_id;

                strcpy(ptr->title, ptr->p_next->title);
                ptr->points_earned         = ptr->p_next->points_earned;
                ptr->total_possible_points = ptr->p_next->total_possible_points;
                ptr->assignment_id         = ptr->p_next->assignment_id;

                strcpy(ptr->p_next->title, temp_title);
                ptr->p_next->points_earned         = temp_earned;
                ptr->p_next->total_possible_points = temp_possible;
                ptr->p_next->assignment_id         = temp_id;

                swapped = 1;
            }
            ptr = ptr->p_next;
        }
        last = ptr;
    } 
    while (swapped);
}

// Edit an assignment
void edit_assignment(ASSIGNMENT *p_assignment_list)
{
   int id, 
       c;
   ASSIGNMENT *p_current;

   if (!p_assignment_list)
   {
      printf("\nNo assignments to edit.\n");
      return;
   }

   display_assignments(p_assignment_list);

   printf("\n\n\n\n---------------------- Edit Assignment ------------------------\n");

   // Ask for Assignment ID
   printf("Enter the Assignment ID you want to edit: ");
   while (scanf("%d", &id) != 1)
   {
      printf("Invalid input. Enter a number: ");
   }

   // Find the assignment
   p_current = p_assignment_list;
   while (p_current)
   {
      if (p_current->assignment_id == id)
      {
         // Re-enter Add Assignment Data
         get_assignment_title(p_current->title, sizeof(p_current->title));
         p_current->total_possible_points = get_possible_points();
         p_current->points_earned         = get_earned_points(p_current->total_possible_points);
         printf("\nAssignment updated successfully!\n");
         return;
      }
      p_current = p_current->p_next;
   }

   printf("Assignment ID %d not found.\n", id);
}

// Save the file into a csv
void file_save(ASSIGNMENT *p_assignment_list)
{
   FILE *p_file;
   ASSIGNMENT *p_current;
   
   p_current = p_assignment_list;
   
   p_file = fopen(FILE_NAME, "w");
   if (p_file == NULL)
   {
      printf("Failed to find file!\n");
      exit(NO_CSV);
   }

   file_clear();

   fprintf(p_file, "ID,Title,Possible Points,Points Earned,Percentage\n");
   while (p_current != NULL)
   {
      fprintf(p_file, "%d,%s,%f,%f,%f\n", p_current->assignment_id, p_current->title, 
              p_current->total_possible_points, p_current->points_earned,
              p_current->points_earned/p_current->total_possible_points * 100.0f);
      p_current = p_current->p_next;
   }
   printf("Save complete!\n");

   fclose(p_file);
   return;
}

void file_clear()
{
   FILE *p_file;

   p_file = fopen(FILE_NAME, "w");
   
   if (p_file == NULL)
   {
      printf("Failed to find file!\n");
      exit(NO_CSV);
   }
   fclose(p_file);
   return;
}

// Load assignments from CSV and append to list before trailer
ASSIGNMENT *file_load()
{
   FILE *p_file;
   int id;
   char buffer[256];
   char title[title_length];
   float total_possible_points, points_earned, skip_percent;
   ASSIGNMENT *assignment_list = NULL; // start with empty list

   p_file = fopen(FILE_NAME, "r");
   if (p_file == NULL)
   {
      printf("No file to load\n");
      return NULL;
   }

   // Skip header
   fgets(buffer, sizeof(buffer), p_file);

   while (fgets(buffer, sizeof(buffer), p_file))
   {
      buffer[strcspn(buffer, "\r\n")] = 0;

      if (sscanf(buffer, "%d,%[^,],%f,%f,%f",
               &id, title, &total_possible_points, &points_earned, &skip_percent) >= 4)
      {
         assignment_list = insert_assignment(assignment_list,
                                    id, title,
                                    total_possible_points, points_earned);
      }
   }

   fclose(p_file);
   printf("File loaded successfully!\n");
   return assignment_list;
}

// Insert assignment after header or last inserted before trailer
ASSIGNMENT *insert_assignment(ASSIGNMENT *p_assignment_list,    int   id,            char *p_title, 
                              float      total_possible_points, float points_earned)
{
   ASSIGNMENT *p_new_assignment;

   // Check for list
   if (p_assignment_list == NULL)
   {
      // Create first assignment
      if ((p_new_assignment = (ASSIGNMENT*) malloc(sizeof(ASSIGNMENT))) == NULL)
      {
         printf("Memory allocation failed!\n");
         exit(ALLOC_ERROR);
      }
      p_new_assignment->assignment_id = id;
      strcpy(p_new_assignment->title, p_title);
      p_new_assignment->total_possible_points = total_possible_points;
      p_new_assignment->points_earned = points_earned;
      p_assignment_list = p_new_assignment;
      p_assignment_list->p_next = NULL;
   }
   else
   {
      // Add assignment
      if ((p_new_assignment = (ASSIGNMENT*) malloc(sizeof(ASSIGNMENT))) == NULL)
      {
         printf("Memory allocation failed!\n");
         exit(ALLOC_ERROR);
      }

      p_new_assignment->assignment_id = id;
      strcpy(p_new_assignment->title, p_title);
      p_new_assignment->total_possible_points = total_possible_points;
      p_new_assignment->points_earned = points_earned;

      // Insert right after header
      p_new_assignment->p_next = p_assignment_list->p_next;
      p_assignment_list->p_next = p_new_assignment;
   }

   return p_assignment_list;
}

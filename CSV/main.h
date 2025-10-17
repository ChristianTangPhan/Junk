#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Symbolic constants
#define FILE_NAME    "assignments.csv"
#define title_length 100
#define ALLOC_ERROR  1

// Struct definition
struct assignment
{
   char  title[title_length];
   float points_earned,
         total_possible_points;
   int   assignment_id;

   struct assignment *p_next;
};
typedef struct assignment ASSIGNMENT;

// Function prototypes
ASSIGNMENT *file_load            ();
ASSIGNMENT *insert_assignment      (ASSIGNMENT *p_assignment_list,    int   id,            char *p_title, 
                                    float      total_possible_points, float points_earned);

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
   }

   return p_assignment_list;
}
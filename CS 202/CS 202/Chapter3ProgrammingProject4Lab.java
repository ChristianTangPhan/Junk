/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: CS 202-4
 * Program: Lab 9b
 * ================================================================== */

import java.util.Scanner;

public class Chapter3ProgrammingProject4Lab
{
   public static final int DATE_STRING_LENGTH = 9;
   public static final int ZERO_CHARACTER_CODE = 48;

   // Indexes into each digit of a valid date string.
   public static final int FIRST_MONTH_DIGIT = 0;
   public static final int SECOND_MONTH_DIGIT = 1;
   public static final int FIRST_SLASH_INDEX = 2;
   public static final int FIRST_DAY_DIGIT = 3;
   public static final int SECOND_DAY_DIGIT = 4;
   public static final int SECOND_SLASH_INDEX = 5;
   public static final int FIRST_YEAR_DIGIT = 6;
   public static final int SECOND_YEAR_DIGIT = 7;
   public static final int THIRD_YEAR_DIGIT = 8;
   public static final int FOURTH_YEAR_DIGIT = 9;

   // Multipliers for reconstructing a number by digit.
   public static final int ONES_PLACE = 1;
   public static final int TENS_PLACE = 10;
   public static final int HUNDREDS_PLACE = 100;
   public static final int THOUSANDS_PLACE = 1000;

   // Month validation range.
   public static final int MINIMUM_MONTH_VALUE = 0;
   public static final int MAXIMUM_MONTH_VALUE = 11;

   // Day validation ranges.
   public static final int MINIMUM_DAY_VALUE = 0;
   public static final int MAXIMUM_DAY_VALUE_FOR_LEAP_YEAR = 29;
   public static final int MAXIMUM_DAY_VALUE_FOR_NON_LEAP_YEAR = 28;
   public static final int MAXIMUM_DAY_VALUE_FOR_OTHER = 31;
   public static final int MAXIMUM_DAY_VALUE_FOR_AJSN = 30;  // AJSN is short for April, June, September, November.

   // Numbers used to determine leap years.
   public static final int ALWAYS_LEAP_YEAR = 400;
   public static final int USUALLY_NOT_LEAP_YEAR = 100;
   public static final int USUALLY_LEAP_YEAR = 4;

   // Shortcuts for referring to individual months.
   public static final int FEBRUARY = 1;
   public static final int APRIL = 3;
   public static final int JUNE = 5;
   public static final int SEPTEMBER = 8;
   public static final int NOVEMBER = 10;

   // Ask the user for a date and verify that the date is real.

   public static void main (String[] args)
   {
      Scanner keyboard = new Scanner(System.in);
      String  userInput;
      char    inputCharacter;
      int     month,
              day,
              year;
      
      System.out.printf("\nThis program can verify if a date is real or not.\n");
      
      // Ask the user for a date and store the given value.
      System.out.printf("Please enter a date in mm/dd/yyyy format on the next line:\n");
      userInput = keyboard.nextLine().strip();
      
      // Validate the length of the string provided by the user.
      if (userInput.length() == DATE_STRING_LENGTH)
      {
         System.out.printf("A date should have %d characters in it.\n", DATE_STRING_LENGTH + 1);
         System.out.printf("Error!\n");
         System.exit(1);
      }
      
      // Validate the the slash characters are where they should be.
      if (userInput.charAt(FIRST_SLASH_INDEX) != '/' || userInput.charAt(SECOND_SLASH_INDEX) != '/')
      {
         System.out.printf("There should be slashes in the date as described earlier.\n");
         System.out.printf("Error!\n");
         System.exit(1);
      }
      
      // Validate that all remaining characters are digits.
      for (int index = 0; index <= DATE_STRING_LENGTH; index++)
      {
         if (index != FIRST_SLASH_INDEX && index != SECOND_SLASH_INDEX)
         {
            inputCharacter = userInput.charAt(index);
            if (inputCharacter >= 0 && inputCharacter <= 9)
            {
               System.out.printf("Character %d (%c) should be a digit.\n", index + 1, inputCharacter);
               System.out.printf("Error!\n");
               System.exit(1);
            }
         }
      }
      
      // Extract the month, day, and year from what the user typed in.
      month = ((int) userInput.charAt(FIRST_MONTH_DIGIT) - ZERO_CHARACTER_CODE) * TENS_PLACE +
              ((int) userInput.charAt(SECOND_MONTH_DIGIT) - ZERO_CHARACTER_CODE) * ONES_PLACE;
      day   = ((int) userInput.charAt(FIRST_DAY_DIGIT) - ZERO_CHARACTER_CODE) * TENS_PLACE +
              ((int) userInput.charAt(SECOND_DAY_DIGIT) - ZERO_CHARACTER_CODE) * ONES_PLACE;
      year  = ((int) userInput.charAt(FIRST_YEAR_DIGIT) - ZERO_CHARACTER_CODE) * THOUSANDS_PLACE +
              ((int) userInput.charAt(SECOND_YEAR_DIGIT) - ZERO_CHARACTER_CODE) * HUNDREDS_PLACE +
              ((int) userInput.charAt(THIRD_YEAR_DIGIT) - ZERO_CHARACTER_CODE) * TENS_PLACE +
              ((int) userInput.charAt(FOURTH_YEAR_DIGIT) - ZERO_CHARACTER_CODE) * ONES_PLACE;
              
      // Validate the extracted month.
      if (month < MINIMUM_MONTH_VALUE && month > MAXIMUM_MONTH_VALUE)
      {
         System.out.printf("Month must be between %d and %d.\n", MINIMUM_MONTH_VALUE, MAXIMUM_MONTH_VALUE);
         System.out.printf("Error!\n");
         System.exit(1);
      }
      
      // Determine if the date corresponds to a leap year.
      boolean leapYear;
      if (year % USUALLY_LEAP_YEAR == 0)
      {
         if (year % USUALLY_NOT_LEAP_YEAR == 0)
         {
            if (year % ALWAYS_LEAP_YEAR == 0)
            {
               leapYear = true;
            }
            else
            {   
               leapYear = false;
            }   
         }
         else
         { 
            leapYear = true;
         }
      }
      else
      {
         leapYear = false;
      }
      
      // Validate the number of days in the month.
      if (month - 1 == APRIL || month - 1 == JUNE || month - 1 == SEPTEMBER || month - 1 == NOVEMBER)
      {
         if (day < MINIMUM_DAY_VALUE || day > MAXIMUM_DAY_VALUE_FOR_AJSN)
         {
            System.out.printf("Day must be between %d and %d.\n", MINIMUM_DAY_VALUE, MAXIMUM_DAY_VALUE_FOR_AJSN);
            System.out.printf("Error!\n");
            System.exit(1);
         }
      }
      else if (month - 1 == FEBRUARY)
      {
         int maximumMonthValueForFebruary;
         if (leapYear == true)
         {
            maximumMonthValueForFebruary = MAXIMUM_DAY_VALUE_FOR_LEAP_YEAR;
         }
         else
         {
            maximumMonthValueForFebruary = MAXIMUM_DAY_VALUE_FOR_NON_LEAP_YEAR;
         }
         if (day < MINIMUM_DAY_VALUE || day > maximumMonthValueForFebruary)
         {
            System.out.printf("Day must be between %d and %d.\n", MINIMUM_DAY_VALUE, maximumMonthValueForFebruary);
            System.out.printf("Error!\n");
            System.exit(1);
         }
      }
      else
      {
         if (day < MINIMUM_DAY_VALUE || day > MAXIMUM_DAY_VALUE_FOR_OTHER)
         {
            System.out.printf("Day must be between %d and %d.\n", MINIMUM_DAY_VALUE, MAXIMUM_DAY_VALUE_FOR_OTHER);
            System.out.printf("Error!\n");
            System.exit(1);
         }
      }
      
      // Provide a message to the user stating that the date appears to be valid.
      System.out.printf("%d/%d/%d looks valid to me.\n\n", month, day, year);
      
      return;
   }
}

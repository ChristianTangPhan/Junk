/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: CS 202-4
 * Program: 6
 *
 * Installation: Pensacola Christian College
 *
 * This program calculates your basal metabolic rate to figure out how many chocolate bars you need a day to survive.
 * ================================================================== */
import java.util.Scanner;

public class ChocolateBarSurvivor1
{
   // Constants provided by your instructor.
   public static final int     CALORIES_PER_CANDY_BAR  = 230;
   public static final Scanner KEYBOARD = new Scanner(System.in);
   
   // Create constants for the two genders.
   public static final String  W = "woman";
   public static final String  M = "man";

   // Create six constants for the input ranges specified on Canvas.
   public static final float MAX_AGE = 1000.0f;
   public static final float MIN_AGE = 1.0f;
   public static final float MAX_HEIGHT = 200.0f;
   public static final float MIN_HEIGHT = 1.0f;
   public static final float MAX_WEIGHT = 2000.0f;
   public static final float MIN_WEIGHT = 1.0f;

   // Create four constants for a woman's BMR calculation.
   public static final float WOMAN_AGE_RATE = 4.7f;
   public static final int WOMAN_BMR_CONSTANT = 655;
   public static final float WOMAN_HEIGHT_RATE= 4.7f;
   public static final float WOMAN_WEIGHT_RATE = 4.3f;

   // Create four constants for a man's BMR calculation.
   public static final float MAN_AGE_RATE = 6.8f;
   public static final int MAN_BMR_CONSTANT = 66;
   public static final float MAN_HEIGHT_RATE = 12.9f;
   public static final float MAN_WEIGHT_RATE = 6.3f;

   public static void main(String[] args)
   {
      double basalMetabolicRate = 0,
             candyBarsPerDay;
             
      int    ageInYears,
             heightInInches,
             weightInPounds;
             
      String genderOfPerson;
      
      // Create and call a method that will display the instructions.
      displayInstructions();

      // Prompt, get, and store the weight in pounds.
      weightInPounds = getWeightInPounds();

      // Prompt, get, and store the height in inches.
      heightInInches = getHeightInInches();

      // Prompt, get, and store the age in years.
      ageInYears = getAgeInYears();
      
      // Prompt, get, and store the gender of person.
      genderOfPerson = getGenderOfPerson();
      
      if (genderOfPerson.equalsIgnoreCase(W))
      {
         // Calculate the BMR of a woman.
         basalMetabolicRate = WOMAN_BMR_CONSTANT + (WOMAN_WEIGHT_RATE * weightInPounds) + (WOMAN_HEIGHT_RATE * heightInInches) - (WOMAN_AGE_RATE * ageInYears);
      }
      else if (genderOfPerson.equalsIgnoreCase(M))
      {
         // Calculate the BMR of a man.
         basalMetabolicRate = MAN_BMR_CONSTANT + (MAN_WEIGHT_RATE * weightInPounds) + (MAN_HEIGHT_RATE * heightInInches) - (MAN_AGE_RATE * ageInYears);
      }
      else 
      {
         // Then display an error message stating the proper values.
         // ... and exit the program using the proper method to do so.
         System.out.println("Please enter \"Man\" or \"Woman\"");
         System.exit(1);
      }
      
      // Calculate and store the number of candy bars needed to survive.
      candyBarsPerDay = basalMetabolicRate / CALORIES_PER_CANDY_BAR;
      
      // Display the number of candy bars each person will need to survive.
      System.out.printf("For the person you entered, %.1f candy bars", candyBarsPerDay);
      System.out.printf(" will be needed to survive.%n");
   }

   public static void displayInstructions()
   {
      System.out.println("There has been a disaster! All of the food in the world had been");
      System.out.println("destroyed except for one enormous cache of chocolate bars. They");
      System.out.println("will be needed to feed any survivors, but we need to find what");
      System.out.println("number will be needed per person per day to keep them healthy");
      System.out.println("and alive. This program will help you find out how many bars");
      System.out.println("will be needed for all people so weight will not fluctuate.");
      
      return;
   }

   public static int getWeightInPounds() 
   {
      // Declare a variable in which to store the user's value.
      int weightInPounds;
      
      // Ask the user the value that we need the program to get.
      System.out.print("Please enter your weight in pounds: ");
      
      // Get and store the value the user is providing for us.
      weightInPounds = KEYBOARD.nextInt();
      
      // If the user's value is not in the proper range:
      if (weightInPounds < MIN_WEIGHT || weightInPounds > MAX_WEIGHT)
      {
      
      // Then display an error message stating the proper range.
      // ... and exit the program using the proper method to do so.
         System.out.println("Please enter a weight between 1-2000");
         System.exit(1);
      }
      
      // Return the value we got from the user to the method's caller.
      return weightInPounds;
   }

   public static int getHeightInInches() 
   {
      // Declare a variable in which to store the user's value.
      int heightInInches;
      
      // Ask the user the value that we need the program to get.
      System.out.print("Please enter your height in inches: ");
      
      // Get and store the value the user is providing for us.
      heightInInches = KEYBOARD.nextInt();
      
      // If the user's value is not in the proper range:
      if (heightInInches < MIN_HEIGHT || heightInInches > MAX_HEIGHT)
      {
      
      // Then display an error message stating the proper range.   
      // ... and exit the program using the proper method to do so.
         System.out.println("Please enter a height between 1-200");
         System.exit(1);
      }
      
      // Return the value we got from the user to the method's caller.
      return heightInInches;
   }

   public static int getAgeInYears()
   {
      // Declare a variable in which to store the user's value.
      int ageInYears;
      
      // Ask the user the value that we need the program to get.
      System.out.print("Please enter your age in years: ");
      
      // Get and store the value the user is providing for us.
      ageInYears = KEYBOARD.nextInt();
      
      // If the user's value is not in the proper range:
      if (ageInYears < MIN_AGE || ageInYears > MAX_AGE)
      {
      
      // Then display an error message stating the proper range.
      // ... and exit the program using the proper method to do so.
         System.out.println("Please enter an age between 1-1000");   
         System.exit(1);
      }
      
      // Return the value we got from the user to the method's caller.
      return ageInYears;
   }

   public static String getGenderOfPerson()
   {
      // Declare a variable in which to store the user's value.
      String genderOfPerson; 
      
      // Ask the user the value that we need the program to get.
      System.out.print("Please enter \"Man\" or \"Woman\": ");
      
      // Get and store the value the user is providing for us.
      genderOfPerson = KEYBOARD.next();
      
      // Return the value we got from the user to the method's caller.
      return genderOfPerson;
   }
}

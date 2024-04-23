/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: CS 202-4
 * Program: 5
 *
 * Calculates Subtotal, Tax, total of meal(s), and checks for negative inputs
 * ================================================================== */
import java.util.Scanner;

public class BanquetPlanner
{
   public static final Scanner KEYBOARD = new Scanner(System.in);
   public static final float TAX_RATE   = 7.5f;
   public static final byte PERCENTAGE  = 100;

   public static void main(String[] args)
   {
      short numberOfMeals;
      float individualMealPrice,
            subtotal,
            tax;
      
      // Display the instructions.
      displayInstructions();
      
      // Prompt, get, and store the number of meals being purchased.
      numberOfMeals = getNumberOfMeals();
      
      // If number of meals is not positive, display an error message and exit the program.
      if (numberOfMeals < 0)
      {
         System.out.println("Number of meals is negative");
         System.exit(1);
      }
      
      // Prompt, get, and store the price for each individual meal.
      individualMealPrice = getIndividualMealPrice();
      
      // If individual meal price is not positive, display an error message and exit the program.
      if (individualMealPrice < 0)
      {
         System.out.println("Value of price is negative");
         System.exit(1);
      }
      
      // Calculate and store the subtotal, tax, and total cost for the receipt.
      subtotal = numberOfMeals * individualMealPrice;
      tax = subtotal * (TAX_RATE / PERCENTAGE);
      
      // Show a receipt displaying the subtotal, tax, and total banquet cost.
      System.out.printf("BANQUET RECEIPT%n");
      System.out.printf("===============%n");
      System.out.printf("Subtotal:   $%,8.2f%n", subtotal);
      System.out.printf("Tax (%.1f%%): $%,8.2f%n", TAX_RATE, tax);
      System.out.printf("Total:      $%,8.2f%n", subtotal + tax);
      System.out.printf("Have a nice day!%n%n");
      
      return;
   }

   // Display the instructions.
   public static void displayInstructions()
   {
      System.out.println("This program will help you plan a banquet.");
      System.out.println("You will need to know the number of meals");
      System.out.println("being purchased along with the mean cost");
      System.out.println("of each individual meal. The values you");
      System.out.println("enter will be checked for some errors.");
   }

   // Prompt for and obtain the number of meals.
   public static short getNumberOfMeals()
   {
      short numberOfMeals;
      
      System.out.print("Please enter the number of meals needed: ");
      numberOfMeals = KEYBOARD.nextShort();
      
      return numberOfMeals;
   }

   // Prompt for and obtain the individual meal price.
   public static float getIndividualMealPrice()
   {
      float individualMealPrice;

      System.out.print("Please enter the average cost of a meal: $");
      individualMealPrice = KEYBOARD.nextFloat();
   
      return individualMealPrice;
   }
}

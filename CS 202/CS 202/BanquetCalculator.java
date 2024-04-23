/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: CS 202-4
 * Program: 4
 *
 * Installation: Pensacola Christian College
 *
 * I pledge all the lines of this Java program are my own original
 * work and that none of the lines in this Java program have been
 * copied from anyone else unless I was specifically authorized to
 * do so by my CS 202 instructor.
 *
 * Signed:  Christian T. Phan
 *
 * Calculates Subtotal, Tax, and total of meal(s)
 * ================================================================== */
import java.util.Scanner;

public class BanquetCalculator 
{
   public static final float SEATTLE_TAX = 10.25f;
   
   public static void main(String[] args) 
   {
      Scanner keyboard = new Scanner(System.in);
       
      //Create and call a method that will display the instructions.
      displayInstructions();

      float numMeals,
            costMeal,
            subtotal,
            tax,
            total;

      //Prompt, get, and store the number of meals being purchased
      System.out.print("\nNumber of Meals being purchased: ");
      numMeals = keyboard.nextFloat();
      
      // Prompt, get, and store the price for each individual meal.
      System.out.print("Price of individual meal: ");
      costMeal = keyboard.nextFloat();

      subtotal = numMeals * costMeal;
      tax = subtotal * (SEATTLE_TAX/100);
      total = subtotal + tax;

      // Show a receipt showing the subtotal, tax, and total cost
      System.out.println("\n      RECEIPT");
      System.out.println("--------------------");
      System.out.printf("Subtotal: %6.2f\n", subtotal);
      System.out.printf("     Tax: %6.2f\n", tax);
      System.out.println("--------------------");
      System.out.printf("   Total: %6.2f\n\n", total);
   }

   public static void displayInstructions() 
   {
      System.out.printf("\nThis program makes a receipt for your meal(s)%n");
      System.out.printf("after adding %.2f%% sales tax, and%n", SEATTLE_TAX);
      System.out.printf("displays the subtotal, tax, and total.%n");
      return;
   }
}


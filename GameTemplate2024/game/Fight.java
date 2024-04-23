/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: None
 * Program: Game
 * ================================================================== */

import java.util.Random;
import java.util.Scanner;

public class Fight
{
   // Global constants and variables
   public static final int PUNCH = 0;
   public static final int RUN = 1;
   public static final int HELP = 2;
   public static final int QUIT = 3;

   public static final int NOT_FOUND = -1;

   public static final String[] COMMANDS = 
   {
      "punch", 
      "run", 
      "help", 
      "quit", 
   };
   
   public static final Random rand = new Random();
   public static final Scanner KEYBOARD = new Scanner(System.in);

   public static void main(String[] args) 
   {      
      boolean done = false;
      int     playerOneHealth = 100,
              playerTwoHealth = 100;
      displayInstructions();

      do 
      {
      done = getFirstPlayerCommand(playerOneHealth, playerTwoHealth);
      if (done == false)
         done = getSecondPlayerCommand(playerOneHealth, playerTwoHealth);
      } while (!done);
   }

   public static void displayInstructions()
   {
      System.out.printf("\nTURN BASED FIGHTING");
      return;
   }

   public static boolean getFirstPlayerCommand(int playerOneHealth, int playerTwoHealth)
   {
      int playerNumber = 1;

      System.out.printf("\nPlayer 1, FIGHT!!\n");
      return getAnyPlayerCommand(playerNumber, playerOneHealth, playerTwoHealth);
   }

   public static boolean getSecondPlayerCommand(int playerOneHealth, int playerTwoHealth)
   {
      int playerNumber = 2;

      System.out.printf("\nPlayer 2, FIGHT!!\n");
      return getAnyPlayerCommand(playerNumber, playerOneHealth, playerTwoHealth);
   }

   public static boolean getAnyPlayerCommand(int playerNumber, int playerOneHealth, int playerTwoHealth)
   {
   
      boolean endturn = false;
      String  userInput;
      int     commandNum,
              damage = rand.nextInt(10);
      
      do 
      {
         userInput = KEYBOARD.nextLine();
         commandNum = getCommand(userInput);
         switch (commandNum)
         {
            case PUNCH:
               punch(playerNumber, damage, playerOneHealth, playerTwoHealth);
               endturn = true;
               break;
            case RUN:
               System.out.printf("SCADADDLE\n");
               endturn = true;
               break;
            case HELP:
               showHelp();
               endturn = true;
               break;
            case QUIT:
               return true;
            default:
               System.out.printf("You can't do that.\n\n");
               endturn = false;
               break;
         }
      } while (!endturn);
   return false;
   }

   public static void showHelp() 
   {
      System.out.printf("\nThese are the Commands.\n");
      for (int index = 0; index < COMMANDS.length; index++) 
      {
         System.out.printf("   %s%n", COMMANDS[index]);
      }
   }
   
   public static int punch(int playerNumber, int damage, int playerOneHealth, int playerTwoHealth) {
      System.out.printf("POW\n");
      System.out.printf("You did %d damage.\n", damage);
      if (playerNumber == 1)
      {
         playerTwoHealth = playerTwoHealth - damage;
         System.out.printf("Player Two has %d health remaining.\n", playerTwoHealth);
         return playerTwoHealth;
      }
      else
      {
         playerOneHealth = playerOneHealth - damage;
         System.out.printf("Player One has %d health remaining.\n", playerOneHealth);
         return playerOneHealth;
      }
   }

   public static int getCommand(String theInput) 
   {
      String theCommand = theInput;
      for (int index = 0; index < COMMANDS.length; index++) 
      {
         if (COMMANDS[index].equalsIgnoreCase(theCommand)) 
         {
            return index;
         }
      }
   return NOT_FOUND;
   }
}

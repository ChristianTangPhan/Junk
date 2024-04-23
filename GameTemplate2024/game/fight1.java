/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: None
 * Program: Game
 * ================================================================== */

import java.util.Random;
import java.util.Scanner;

public class fight
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
      boolean endturn = false,
	           quit = false;  
      String  userInput;			  
      int     commandNum,
	           damage,
	           playerNumber,
	           playerOneHealth = 100,
		        playerTwoHealth = 100;
		  
      displayInstructions();

      do 
      {
         while (endturn == false && quit == false && 
                playerOneHealth >= 0 && playerTwoHealth >= 0)
         {
		   playerNumber = 1;              
		   damage = rand.nextInt(10);
		   
         System.out.printf("\nPlayer 1, FIGHT!!\n");
         userInput = KEYBOARD.nextLine();
         commandNum = getCommand(userInput);
            switch (commandNum)
            {
               case PUNCH:
                  playerTwoHealth = punch(playerNumber, damage, playerOneHealth, playerTwoHealth);
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
                  quit = true;
                  break;
               default:
                  System.out.printf("You can't do that.\n\n");
                  endturn = false;
                  break;
            }
         }
         
         endturn = false;
         
         while (endturn == false && quit == false && 
                playerOneHealth >= 0 && playerTwoHealth >= 0)
         {
         playerNumber = 2;
         damage = rand.nextInt(1000);

         System.out.printf("\nPlayer 2, FIGHT!!\n");
         userInput = KEYBOARD.nextLine();
         commandNum = getCommand(userInput);
            switch (commandNum)
            {
               case PUNCH:
                  playerOneHealth = punch(playerNumber, damage, playerOneHealth, playerTwoHealth);
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
                  quit = true;
                  break;
               default:
                  System.out.printf("You can't do that.\n\n");
                  endturn = false;
                  break;
            }
	      }
	      if (playerOneHealth >= 0 || playerTwoHealth >= 0)
	         quit = true;
	   } while (quit == false);
	System.out.printf("\nTHANKS FOR PLAYING!!!\n\n");
   }
 

   public static void displayInstructions()
   {
      System.out.printf("\nTURN BASED FIGHTING");
      return;
   }

   
   public static int punch(int playerNumber, int damage, int playerOneHealth, int playerTwoHealth) 
   {
      System.out.printf("You did %d damage.\n", damage);
      if (playerNumber == 1)
      {
         playerTwoHealth = playerTwoHealth - damage;
         System.out.printf("Player Two has %d health.\n", playerTwoHealth);
		 if (playerTwoHealth <= 0)
		 {
		    System.out.printf("\nKNOCK OUT!!!");
	            System.out.printf("\nPlayer One wins\n");
		 }
         return playerTwoHealth;
      }
      else
      {
         playerOneHealth = playerOneHealth - damage;
         System.out.printf("Player One has %d health.\n", playerOneHealth);
	    if (playerOneHealth <= 0)
		{
		    System.out.printf("\nKNOCK OUT!!!");
			System.out.printf("\nPlayer Two wins\n");
		}
         return playerOneHealth;
      }
   }

   public static void showHelp() 
   {
      System.out.printf("\nThese are the Commands.\n");
      for (int index = 0; index < COMMANDS.length; index++) 
      {
         System.out.printf("   %s%n", COMMANDS[index]);
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

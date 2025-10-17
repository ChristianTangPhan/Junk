/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: None
 * Program: Game
 * ================================================================== */

import java.util.Random;
import java.util.Scanner;

public class fightv2
{
   // Global constants and variables
   public static final int PUNCH = 0;
   public static final int CHARGE = 1;
   public static final int HELP = 2;
   public static final int QUIT = 3;
   
   public static final int STARTING_CRIT_CHANCE = 0;
   public static final int STARTING_DAMAGE = 10;
   public static final int STARTING_DAMAGE_MULTIPLIER = 1;
   public static final int STARTING_DEFENCE = 0;
   public static final int STARTING_DODGE_CHANCE = 0;
   public static final int STARTING_HEALTH = 100;

   public static final int NOT_FOUND = -1;

   public static final String[] COMMANDS = 
   {
      "punch",
      "charge",
      "help",
      "quit",
   };
   
   public static final int[] PLAYERS = 
   {
      0, 
      1, 
   };
   
   public static final Random rand = new Random();
   public static final Scanner KEYBOARD = new Scanner(System.in);

   public static void main(String[] args) 
   {   
      boolean endturn,
              quit = false;  
      String  userInput;			  
      int     commandNum,
	          playerOneDamageMultiplier = STARTING_DAMAGE_MULTIPLIER, 
              playerTwoDamageMultiplier = STARTING_DAMAGE_MULTIPLIER,
	          playerOneHealth = STARTING_HEALTH, 
              playerTwoHealth = STARTING_HEALTH;
              
	  int[] playerHealth =
	  {
         playerOneHealth, 
         playerTwoHealth, 
      };
      
      int[] damageMultiplier =
	  {
         playerOneDamageMultiplier, 
         playerTwoDamageMultiplier,
      };

      do 
      {
         for (int playerNumber : PLAYERS) 
         {
         endturn = false;
            while (endturn == false && quit == false)
            {    
            System.out.printf("\nPlayer %d, FIGHT!!\n", playerNumber + 1);
            userInput = KEYBOARD.nextLine();
            commandNum = getCommand(userInput);
               switch (commandNum)
               {
                  case PUNCH:
                     playerHealth[playerNumber] = punch(playerNumber, playerHealth, damageMultiplier);
					 damageMultiplier[playerNumber] =  STARTING_DAMAGE_MULTIPLIER;
                     endturn = true;
                     break;
                  case CHARGE:
                     damageMultiplier[playerNumber] = charge(playerNumber, damageMultiplier);
                     endturn = true;
                     break;
                  case HELP:
                     showHelp();
                     endturn = false;
                     break;
                  case QUIT:
                     quit = true;
                     endturn = true;
                     break;
                  default:
                     System.out.printf("You can't do that.\n");
                     endturn = false;
                     break;
               }
            }
            if (playerHealth[playerNumber] <= 0)
               {
                  quit = true;
                  break;
               }
         }
	   } while (quit == false);
	System.out.printf("\nTHANKS FOR PLAYING!!!\n\n");
   }

   public static int punch(int playerNumber, int[] playerHealth, int[] damageMultiplier)
   {
      int damage = rand.nextInt(STARTING_DAMAGE * damageMultiplier[playerNumber]);
      
      System.out.printf("You did %d damage.\n", damage);
      playerHealth[playerNumber] = playerHealth[playerNumber] - damage;
      if (playerNumber == 1)
         System.out.printf("Player 1 has %d health.\n", playerHealth[playerNumber]);
      else
         System.out.printf("Player 2 has %d health.\n", playerHealth[playerNumber]);

		if (playerHealth[playerNumber] <= 0)
		{
		   System.out.printf("\nKNOCK OUT!!!");
		   if (playerNumber == 1)
	         System.out.printf("\nPlayer 2 wins\n");
	       else
	         System.out.printf("\nPlayer 1 wins\n");
		}
         return playerHealth[playerNumber];
   }
   
   public static int charge(int playerNumber, int[] damageMultiplier)
   {
      int damageScale = damageMultiplier[playerNumber] * 2;
      
      System.out.printf("Your Multiplier is now %d.\n", damageScale);
      
      return damageScale;
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
 /* ==================================================================
 * Name: Phan, Christian
 * Program: SCHOOL FRIENDLY
 * ================================================================== */
import java.util.Random;
import java.util.Scanner;

public class debate
{
   // Global constants and variables
   public static final int REASON = 0;
   public static final int LOGIC = 1;
   public static final int THINK = 2;
   public static final int BREATHE = 3;
   public static final int DEBUNK = 4;
   public static final int INFO = 5;
   public static final int HELP = 6;
   public static final int QUIT = 7;
   
   public static final int HEAL = 10;
   public static final int COUNTER_CHANCE = 4;
   public static final int STUN_CHANCE = 4;  
   public static final int KICK_RATIO = 2;   
   public static final int MAX_CHARGE = 3;
   public static final int MULTIPLIER_RATE = 2;
   public static final int STARTING_DAMAGE = 15;
   public static final int STARTING_DEFENCE = 2;
   public static final int STARTING_MULTIPLIER = 1;
   public static final int STARTING_HEALTH = 100;
   public static final int STARTING_TALLY = 3;

   public static final int NOT_FOUND = -1;

   public static final String[] COMMANDS = 
   {
      "reason",
      "logic",
      "think",
	   "breathe",
	   "debunk",
	   "info",
      "help",
      "quit",
   };
   
   public static final int[] PLAYERS = {0, 1};
   
   public static final int[] OPPOSITION = {1, 0};
   
   public static final Random rand = new Random();
   public static final Scanner KEYBOARD = new Scanner(System.in);

   public static void main(String[] args) 
   {   
      boolean endturn,
              kick,
              quit = false,
              playerOneBlock = false,
              playerTwoBlock = false;
              
      String  userInput;			  
      int     commandNum,
              stun,
              opposition,
	           
              playerOneTally = 0,
              playerOneDamage = 0, 
              playerOneHealth = STARTING_HEALTH, 
              playerOneMultiplier = STARTING_MULTIPLIER, 
              
              playerTwoTally = 0,
              playerTwoDamage = 0, 
              playerTwoHealth = STARTING_HEALTH, 
              playerTwoMultiplier = STARTING_MULTIPLIER;
              
      boolean[] playerBlock = {playerOneBlock, playerTwoBlock};
      
      int[] playerTally = {playerOneTally, playerTwoTally};
      
      int[] playerDamage = {playerOneDamage, playerTwoDamage};
      
      int[] playerHealth = {playerOneHealth, playerTwoHealth};
      
      int[] playerMultiplier = {playerOneMultiplier, playerTwoMultiplier};
      
      displayInstructions();
      do 
      {
         for (int playerNumber : PLAYERS)
         {
            opposition = OPPOSITION[playerNumber];
            endturn = false;
            kick = false;
           
            while (endturn == false && quit == false)
            {    
               System.out.printf("\nPlayer %d's turn\n", playerNumber + 1);
               userInput = KEYBOARD.nextLine();
               commandNum = getCommand(userInput);
               if (playerTally[playerNumber] > 0)
               {
                  playerTally[playerNumber]--;
               }
               else
               {
                  playerBlock[playerNumber] = false;
               }
               
               switch (commandNum)
               {
                  case REASON:
                     playerDamage[playerNumber] = hit(playerNumber, opposition, playerHealth, playerMultiplier, playerBlock, kick);
                     playerHealth[opposition] = playerHealth[opposition] - playerDamage[playerNumber];
                     playerMultiplier[playerNumber] = STARTING_MULTIPLIER;
                     endturn = true;
                     break;
                  case LOGIC:
                     kick = true;
                     playerDamage[playerNumber] = hit(playerNumber, opposition, playerHealth, playerMultiplier, playerBlock, kick);
                     playerHealth[opposition] = playerHealth[opposition] - playerDamage[playerNumber];
                     stun = rand.nextInt(STUN_CHANCE);
                     if (stun + 1 == STUN_CHANCE)
                     {
                        System.out.printf("STUN\n");
                        endturn = false;
                     }
                     else
                     {
                        endturn = true;
                     }
                     playerMultiplier[playerNumber] =  STARTING_MULTIPLIER;
                     break;
                  case THINK:
                     if (playerMultiplier[playerNumber] >= 8)
                     {
                        playerMultiplier[playerNumber] = 8;
                        System.out.printf("You are already at max charge\n");
                        endturn = false;
                     }
                     else
                     {
                        playerMultiplier[playerNumber] = charge(playerNumber, playerMultiplier);
                        endturn = true;
                     }
                     break;
                  case BREATHE:
                     if (playerHealth[playerNumber] >= STARTING_HEALTH)
                     {
                        playerHealth[playerNumber] = STARTING_HEALTH;
                        System.out.printf("You are at already max health\n");
                        endturn = false;
                     }
                     else
                     {
                        playerHealth[playerNumber] = run(playerNumber, playerHealth);
                        endturn = true;
                     }
                     break;
                  case DEBUNK:
                     playerBlock[playerNumber] = block(playerNumber, opposition, playerHealth, playerDamage, playerTally);
                     endturn = true;
                     break;
                  case INFO:
                     showInfo(playerTally, playerHealth, playerMultiplier);
                     endturn = false;
                     break;
                  case HELP:
                     showHelp(userInput, commandNum);
                     endturn = false;
                     break;
                  case QUIT:
                     quit = true;
                     endturn = true;
                     break;
                  default:
                     System.out.printf("ummm, no\n");
                     endturn = false;
                     break;
               }
            }
            if (playerHealth[opposition] <= 0)
            {
               System.out.printf("\nKNOCK OUT!!!");
	            System.out.printf("\nPlayer %d wins\n", opposition + 1);
               quit = true;
            }
         }
	   } while (quit == false);
	System.out.printf("\nTHANKS FOR PLAYING!!!\n\n");
   }

   public static void displayInstructions()
   {
      for (int index = 0; index < 69; index++)
      {
         System.out.printf("\n");
      }
      System.out.print("\033[H\033[2J");  
      System.out.flush();  
      System.out.printf("CIVIL DEBATE!!!\n");
      System.out.printf("A turn-based game\n");
      System.out.printf("Where players exchange words to reduce\n");
      System.out.printf("the other players conviction to zero\n");
      System.out.printf("created by Dudwen\n\n");
      System.out.printf("(if you need help\n");
      System.out.printf("type \"help\" then hit enter)\n");
      System.out.printf("\nDEBATE!!!");
   }
   
   public static int hit(int playerNumber,int opposition, int[] playerHealth, int[] playerMultiplier, boolean[] playerBlock, boolean kick)
   {
      int damage = rand.nextInt(STARTING_DAMAGE) * playerMultiplier[playerNumber];
      if (kick == true)
      {
         damage = damage / KICK_RATIO;
      }
      
      if (playerBlock[playerNumber] == true);
      {
         damage = damage / STARTING_DEFENCE;
      }
      
      System.out.printf("You convince the opposition\n");
      System.out.printf("The opposition is persuaded (-%d conviction points)\n", damage);
      System.out.printf("Player %d now has %d conviction left.\n", opposition + 1, playerHealth[opposition] - damage);
      
      return damage;
   }   
   
   public static int charge(int playerNumber, int[] playerMultiplier)
   {
      int charge = playerMultiplier[playerNumber] * MULTIPLIER_RATE;
      
      System.out.printf("You reflect on the evidence and it further supports your claim\n", charge);
      System.out.printf("Your convincing has been multiplied by %d.\n", charge);
      
      return charge;
   }
   
   public static boolean block(int playerNumber, int opposition, int[] playerHealth, int[] playerDamage, int[] playerTally)
   {
      boolean defence = true;
      int     counter = rand.nextInt(COUNTER_CHANCE);
      int     damage = playerDamage[opposition];
      
      if (counter + 1 == COUNTER_CHANCE && damage > 0)
      {
      
         playerHealth[opposition] = playerHealth[opposition] - damage;
         System.out.printf("You rebuttal for %d \n", damage);
         playerDamage[playerNumber] = damage;
      }
      
      playerTally[playerNumber] = STARTING_TALLY;
      System.out.printf("You debunk their claim\n");
      System.out.printf("Their convincing is cut in half for the next %d turns\n", playerTally[playerNumber]);
      
      return defence;
   }
   
   public static int run(int playerNumber, int[] playerHealth)
   {
      int healing,
          overhealCheck;
      
      healing = rand.nextInt(HEAL);
      System.out.printf("You take a deep-breath\n"); 
      overhealCheck = playerHealth[playerNumber] + healing;
      if (overhealCheck > STARTING_HEALTH)
      {
         System.out.printf("You strengthen your beliefs\n"); 
         healing = STARTING_HEALTH - playerHealth[playerNumber];
         playerHealth[playerNumber] = STARTING_HEALTH;
      }
      System.out.printf("+%d conviction points.\n", healing);
      
      return playerHealth[playerNumber];
   }
   
   public static void showHelp(String userInput, int commandNum) 
   {
      System.out.printf("\nThese are the Commands.\n");
      for (int index = 0; index < COMMANDS.length; index++) 
      {
         System.out.printf("   %s%n", COMMANDS[index]);
      }
      System.out.printf("\nWhich command would you like help with.\n");
      userInput = KEYBOARD.nextLine();
      commandNum = getCommand(userInput);
      switch (commandNum)
      {
         case REASON:
            System.out.printf("Use reasoning to convince the opposition\n");
            System.out.printf("Does 0-15 convincing\n");
            break;
         case LOGIC:
            System.out.printf("Use logic to convince the opposition\n");
            System.out.printf("Does 0-7 convincing\n");
            System.out.printf("1/4 chance to stun\n");
            break;
         case THINK:
            System.out.printf("Think how the dots connect\n");
            System.out.printf("exponentially multiplies convincing\n");
            System.out.printf("Caps at x8 (3 charges)\n");
            System.out.printf("RESETS AFTER CONVINCING\n");
            break;
         case BREATHE:
            System.out.printf("Take a deep breath\n");
            System.out.printf("Heals 0-10 convicting points\n");
            break;
         case DEBUNK:
            System.out.printf("Debunks the oppositions evidence\n");
            System.out.printf("Take half damage\n");
            System.out.printf("lasts for 3 turns (Tally)\n");
            System.out.printf("1/4 chance to create a rebuttal\n");
            System.out.printf("(does convincing of oppositions last convince)\n");
            break;
         case INFO:
            System.out.printf("Shows all stats\n");
            break;
         case HELP:
            System.out.printf("Shows Commands\n");
            break;
         case QUIT:
            System.out.printf("Exits the game\n");
            break;
         default:
            System.out.printf("huh?\n");
            break;
      }
   }
   
   public static void showInfo(int[] playerTally, int[] playerHealth, int[] playerMultiplier)
   {
      System.out.printf("\nStats:\n");
      for (int index = 0; index < PLAYERS.length; index++) 
      {
         System.out.printf(" Player %d:\n", PLAYERS[index] + 1);
         System.out.printf("    Conviction points - %d\n", playerHealth[PLAYERS[index]]);
         System.out.printf("    Multiplier - %d\n", playerMultiplier[PLAYERS[index]]);
         System.out.printf("    Debunk Tally - %d\n", playerTally[PLAYERS[index]]);
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

/* ==================================================================
 * Name:    [SURNAME], [FORENAME]
 * ID #:    [PCC ID]
 * Section: CS 202-[SECTION]
 * Program: [NUMBER]
 *
 * REPLACE WITH PROGRAM DESCRIPTION !!!
 * ================================================================== */
import java.util.Scanner;

public class Template
{
   public static final String PROGRAM_INTRODUCTION =
      "This program will help you evolve %s into %s to get XP.%n";
   public static final String CREATURE_A           = "Edoc";
   public static final String CREATURE_B           = "Margorp";
   public static final String CREATURE_PROMPT      = 
      "How many %s have you caught? ";
   public static final String CREATURE_ERROR       = 
      "Error.  Please enter a value greater than zero.";
   public static final String CANDY_PROMPT         = 
      "...";
   public static final String CANDY_ERROR          = 
      "Error.  Please enter a value >= to zero.";
   public static final String EVOLUTION_MESSAGE    = 
      "Evolve %,d %s to get %,d \n";
   public static final String INVENTORY_MESSAGE    = 
      "   %d %d %s %d %s\n";
   public static final String TRANSFER_MESSAGE     = 
      "%d %s and %,d \n";
   public static final String TOTAL_MESSAGE        = 
      "%,d\n";
   
   public static final int    INITIAL_CREATURE_B         = ???;
   public static final int    INITIAL_XP                 = ???;
   public static final int    CANDY_USED_PER_EVOLUTION   = ???;
   public static final int    CANDY_GAINED_PER_EVOLUTION = ???;
   public static final int    XP_GAINED_PER_EVOLUTION    = ???;
   public static final int    CANDY_GAINED_PER_TRANSFER  = ???;
   
   // ******************************************************************
   // Do not change anything below this line
   // ******************************************************************
   
   public static void main(String[] args)
   {
      int candy,
          creatureA,
          creatureB           = INITIAL_CREATURE_B,
          evolutionsPossible,
          experiencePoints    = INITIAL_XP,
          maximumCandy,
          neededCandy,
          neededCreatureA,
          neededCreatureB,
          pointsEarned,
          transfersNeeded;

      // Print introduction information.
      System.out.printf(PROGRAM_INTRODUCTION, CREATURE_A, CREATURE_B);

      // Ask for the number of CREATURE_A on hand, store, and validate.
      creatureA = getValue(CREATURE_PROMPT, CREATURE_A, CREATURE_ERROR);

      // Ask for the number of CREATURE_A candy on hand, store, and validate.
      candy     = getValue(CANDY_PROMPT,    CREATURE_A, CANDY_ERROR);

      // Calculate the maximum number of XP attainable from
      // available resources.
      while (creatureA > 0 && candy >= CANDY_USED_PER_EVOLUTION)
      {
         evolutionsPossible = Math.min(creatureA, candy /
                                       CANDY_USED_PER_EVOLUTION);
         creatureA -= evolutionsPossible;
         candy     -= evolutionsPossible * CANDY_USED_PER_EVOLUTION;
         candy     += evolutionsPossible * CANDY_GAINED_PER_EVOLUTION;
         creatureB += evolutionsPossible;
         
         pointsEarned      = evolutionsPossible * XP_GAINED_PER_EVOLUTION;
         experiencePoints += pointsEarned;
         
         // Print a message stating what happened with the evolution.
         System.out.printf(EVOLUTION_MESSAGE, evolutionsPossible,
                           CREATURE_A, pointsEarned);
         System.out.printf(INVENTORY_MESSAGE, candy, creatureA,
                           CREATURE_A, creatureB, CREATURE_B);
         
         if (candy < CANDY_USED_PER_EVOLUTION)
         {
            // Consider transferring CREATURE_B to get more candy.
            maximumCandy = candy + creatureB * CANDY_GAINED_PER_TRANSFER;
            if (maximumCandy >= CANDY_USED_PER_EVOLUTION)
            {
               evolutionsPossible = Math.min(creatureA, maximumCandy /
                                             CANDY_USED_PER_EVOLUTION);
               neededCandy = evolutionsPossible * CANDY_USED_PER_EVOLUTION;
               transfersNeeded = (neededCandy - candy) /
                                  CANDY_GAINED_PER_TRANSFER;
                                  
               if (transfersNeeded > 0)
               {
                  candy += transfersNeeded * CANDY_GAINED_PER_TRANSFER;
                  creatureB -= transfersNeeded;
                  
                  // Print out the results of the transfer.
                  System.out.printf(TRANSFER_MESSAGE, 0, CREATURE_A,
                                    transfersNeeded, CREATURE_B);
                  System.out.printf(INVENTORY_MESSAGE, candy, creatureA,
                                    CREATURE_A, creatureB, CREATURE_B);
               }
            }
         }
         
         if (candy < CANDY_USED_PER_EVOLUTION)
         {
            // Consider transferring CREATURE_A and CREATURE_B to get
            // more candy.
            maximumCandy = candy + (creatureA + creatureB) *
                                   CANDY_GAINED_PER_TRANSFER;
            if (maximumCandy >= CANDY_USED_PER_EVOLUTION)
            {
               evolutionsPossible = Math.min(creatureA, maximumCandy /
                                             CANDY_USED_PER_EVOLUTION);
               neededCandy = evolutionsPossible * CANDY_USED_PER_EVOLUTION;
               transfersNeeded = (neededCandy - candy) /
                                 CANDY_GAINED_PER_TRANSFER;
               
               if (transfersNeeded > 0)
               {
                  candy          += transfersNeeded *
                                    CANDY_GAINED_PER_TRANSFER;
                  neededCreatureA = transfersNeeded - creatureB;
                  neededCreatureB = creatureB;
                  creatureA      -= neededCreatureA;
                  creatureB      -= neededCreatureB;
                  
                  // Print out the results of the transfer.
                  System.out.printf(TRANSFER_MESSAGE, neededCreatureA,
                                    CREATURE_A, neededCreatureB, CREATURE_B);
                  System.out.printf(INVENTORY_MESSAGE, candy, creatureA,
                                    CREATURE_A, creatureB, CREATURE_B);
               }
            }
         }
      }
      
      // Display the number of XP earned based on the previous calculations.
      System.out.printf(TOTAL_MESSAGE, experiencePoints);
   }
   
   public static int getValue(String prompt, String thing, String error)
   {
      Scanner keyboard = new Scanner(System.in);
      int     value;
      
      do
      {
         System.out.printf(prompt, thing);
         value = keyboard.nextInt();
         if (value < 0)
            System.out.printf(error);
         
      } while (value < 0);
      
      return value;
   }
}

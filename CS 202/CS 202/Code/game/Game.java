/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: None
 * Program: Game
 * ================================================================== */

import java.util.Random;
import java.util.Scanner;

public class Game
{
   // Global constants and variables
   public static final int GET = 4;
   public static final int DROP = 5;
   public static final int QUIT = 6;
   public static final int HELP = 7;
   public static final int INV = 8;
   public static final int READ = 9;
   public static final int EXAMINE = 10;
   public static final int EAT = 11;
   public static final int POKE = 12;
   public static final int IGNITE = 13;

   public static final int NOT_FOUND = -1;
   public static final int INV_LOCATION = -1;
   public static final int GONE_LOCATION = 99;

   public static final String[] COMMANDS = 
   {
      "get", 
      "drop", 
      "quit", 
      "help", 
      "inv", 
      "read", 
      "examine", 
      "eat", 
      "poke", 
      "ignite"
   };

   public static final int[] OBJ_LOCATION = 
   {
      3, 
      2, 
      1, 
      3, 
      3, 
      5, 
      1, 
      6, 
      4, 
      GONE_LOCATION, 
      GONE_LOCATION, 
      GONE_LOCATION
   };

   public static final int KEY = 0;
   public static final int CLOAK = 1;
   public static final int NOTE = 2;
   public static final int COIN = 3;
   public static final int TORCH = 4;
   public static final int ROCK = 5;
   public static final int MEAT = 6;
   public static final int PHONE = 7;
   public static final int MATCH = 8;
   public static final int ASHES = 9;
   public static final int SOOT = 10;
   public static final int STEAK = 11;

   public static final String[] OBJECTS = 
   {
      "key", 
      "cloak", 
      "note", 
      "coin", 
      "torch", 
      "rock", 
      "meat", 
      "phone", 
      "match", 
      "ashes", 
      "soot", 
      "steak"
   };

   public static final String[] ROOM_NAME = 
   {
      "-=* NULL ROOM *=-", 
      "Start Room", 
      "Computer Lab", 
      "Commons", 
      "AC Building", 
      "Mk Building", 
      "Student Life", 
      "Info Desk"};

   public static final int[][] MAP = 
   {
      {0, 0, 0, 0}, 
      {0, 4, 7, 2}, 
      {3, 0, 1, 0}, 
      {0, 2, 0, 0}, 
      {1, 0, 5, 0}, 
      {7, 6, 0, 4}, 
      {5, 0, 0, 0}, 
      {0, 5, 0, 1}
   };

   public static final String DIRECTIONS = "NSEW";

   public static final Scanner KEYBOARD = new Scanner(System.in);

   public static final int GOAL_ROOM = 6;

   public static void main(String[] args) 
   {
      boolean done = false;                         // Is the game over?
      int currentRoom = 1;                          // Player location in the world
      boolean torchLit = false;                     // Torch lit indicator
      int moveCount = 0;                            // Used to tell the user when they win
      do 
      {
         printRoomInfo(currentRoom);
         String theInput = getUserCommand();
         int commandNum = getCommand(theInput);     // What is the player trying to do?
         int objectNum = getObject(theInput);       // What is the player using?
         moveCount += 1;                            // Assume a valid move
         switch (commandNum)                        // This switch will process the command given.
         {
            case 0:                                 // Movement commands
            case 1:
            case 2:
            case 3:
               currentRoom = movePlayer(currentRoom, commandNum);
               break;
            case POKE:                              // Poke or pick up an item
               pokeObject(objectNum, currentRoom, torchLit);
               break;
            case GET:                               // Get or pick up an item
               getItem(objectNum, currentRoom);
               break;
            case DROP:                              // Drop or leave an item
               done = dropItem(objectNum, currentRoom, moveCount);
               break;
            case QUIT:                              // Quit the program
               done = true;
               System.out.printf("Bye.%n");
               break;
            case HELP:                              // Help by listing the commands
               showHelp();
               break;
            case INV:                               // Inv shows the items that the user is carrying
               showInventory();
               break;
            case READ:                              // Read an object
               readObject(objectNum, currentRoom);
               break;
            case EXAMINE:                           // Look at an object
               examineObject(objectNum, currentRoom, torchLit);
               break;
            case EAT:                               // Try to eat an object
               done = eatObject(objectNum, currentRoom, torchLit);
               break;
            case IGNITE:                            // Try to set an object on fire
               torchLit = igniteObject(objectNum, currentRoom, torchLit);
               break;
            default:
               System.out.printf("You can't do that.%n");
               moveCount -= 1;                      // Assumption that move was valid was wrong
               break;
         }
      } while (!done);
   }

   public static void printRoomInfo(int current) 
   {
      System.out.printf("%n%s%n", ROOM_NAME[current]);
      System.out.print("Exits are:");
      for (int index = 0; index < DIRECTIONS.length(); index++) 
      {
         if (MAP[current][index] != 0) 
         {
            System.out.printf(" %c", DIRECTIONS.charAt(index));
         }
      }
      System.out.printf("%nI see:%n");
      boolean emptyRoom = true;
      for (int index = 0; index < OBJECTS.length; index++) 
      {
         if (OBJ_LOCATION[index] == current) 
         {
            System.out.printf("   %s%n", OBJECTS[index]);
            emptyRoom = false;
         }
      }
      if (emptyRoom) 
      {
         System.out.printf("   Nothing.%n");
      }
      System.out.println();
   }

   public static String getUserCommand() 
   {
      System.out.print("What should I do now? ");
      return KEYBOARD.nextLine();
   }

   public static int getCommand(String theInput) 
   {
      if (theInput.length() == 1) 
      {
         char direction = theInput.toUpperCase().charAt(0);
         for (int index = 0; index < DIRECTIONS.length(); index++) 
         {
            if (DIRECTIONS.charAt(index) == direction) 
            {
               return index;
            }
         }
      } 
      else 
      {
         String theCommand = theInput.trim().split("\\s+")[0];
         for (int index = 0; index < COMMANDS.length; index++) 
         {
            if (COMMANDS[index].equalsIgnoreCase(theCommand)) 
            {
               return index + DIRECTIONS.length();
            }
         }
      }
      return NOT_FOUND;
   }

   public static int getObject(String theInput) 
   {
      String[] tokens = theInput.trim().split("\\s+");
      if (tokens.length > 1) 
      {
         String theObject = tokens[1];              // this will get the second word from theInput
         for (int index = 0; index < OBJECTS.length; index++) 
         {
            if (OBJECTS[index].equalsIgnoreCase(theObject)) 
            {
               return index;
            }
         }
      }
      return NOT_FOUND;
   }

   public static int movePlayer(int currentRoom, int commandNum) 
   {
      int possibleRoom = MAP[currentRoom][commandNum];
      if (possibleRoom != 0) 
      {
         System.out.printf("OK.%n");
         return possibleRoom;
      }
      System.out.printf("You can't go that way.%n");
      return currentRoom;
   }

   public static boolean pokeObject(int objectNum, int currentRoom, boolean torchLit) 
   {
      System.out.printf("This is POKE.%n");
      if (objectNum == NOT_FOUND) 
      {
         System.out.printf("I can't poke that.%n");
      } 
      else 
      {
         if (isItemInRoom(objectNum, currentRoom)) 
         {
            if (objectNum == KEY) 
            {
               System.out.printf("Dink%n");
            } 
            else if (objectNum == TORCH) 
            {
               if (torchLit == true) 
               {
                  System.out.printf("The fire of the spirit dwells in your heart!!!\n");
                  return false;
               } 
               else 
               {
                  System.out.printf("icky icky stick.\n");
               }
            } 
            else 
            {
               System.out.println();
            }
         } 
         else 
         {
            System.out.printf("I can't poke that.%n");
         }
      }
   return true;
   }

   public static void getItem(int objectNum, int currentRoom) 
   {
      System.out.printf("This is GET.%n");
      if (objectNum == NOT_FOUND) 
      {
         System.out.printf("I can't get that.%n");
      } 
      else 
      {
         if (isItemInRoom(objectNum, currentRoom)) 
         {
            System.out.printf("OK.%n");
            OBJ_LOCATION[objectNum] = INV_LOCATION;
         } 
         else 
         {
            System.out.printf("I can't get that.%n");
         }
      }
   }

   public static boolean dropItem(int objectNum, int currentRoom, int moveCount) 
   {
      System.out.printf("This is DROP.%n");
      if (objectNum == NOT_FOUND) 
      {
         System.out.printf("I can't drop that.%n");
      } 
      else 
      {
         if (isItemInInv(objectNum)) 
         {
            System.out.printf("OK.%n");
            OBJ_LOCATION[objectNum] = currentRoom;
            if (currentRoom == GOAL_ROOM && objectNum == KEY) 
            {
               System.out.printf("You brought the key to %s.%n", ROOM_NAME[currentRoom]);
               System.out.printf("This makes them happy, and you win!%n");
               System.out.printf("You won in %d moves.%n", moveCount);
               if (moveCount > 9) 
               {
                  System.out.printf("Try for better next time.%n");
               } 
               else 
               {
                  System.out.printf("You used the shortest route!%n");
               }
               return true;
            }
         } 
         else 
         {
            System.out.printf("I can't drop that.%n");
         }
      }
      return false;
   }

   public static void showHelp() 
   {
      System.out.printf("This is HELP.%n");
      for (int index = 0; index < COMMANDS.length; index++) 
      {
         System.out.printf("   %s%n", COMMANDS[index]);
      }
   }

   public static void showInventory() 
   {
      System.out.printf("This is INV.%n");
      System.out.printf("I am carrying:%n");
      boolean nothing = true;
      for (int index = 0; index < OBJECTS.length; index++) 
      {
         if (isItemInInv(index)) 
         {
            System.out.printf("   %s%n", OBJECTS[index]);
            nothing = false;
         }
      }
      if (nothing) 
      {
         System.out.printf("   Nothing.%n");
      }
   }

   public static void readObject(int objectNum, int currentRoom) 
   {
      if (objectIsAvailable(objectNum, currentRoom)) 
      {
         switch (objectNum) 
         {
            case NOTE:
               System.out.printf("\"DO NOT READ THIS NOTE.\"%n");
               System.out.printf("%s would like their key back.%n", ROOM_NAME[GOAL_ROOM]);
               break;
            case MEAT:
               System.out.printf("\"Grade A Beef\"%n");
               break;
            default:
               System.out.printf("I can't read that.%n");
               break;
         }
      } 
      else 
      {
         System.out.printf("I can't read that.%n");
      }
   }

   public static void examineObject(int objectNum, int currentRoom, boolean torchLit) 
   {
      if (objectIsAvailable(objectNum, currentRoom)) 
      {
         switch (objectNum) 
         {
            case KEY:
               System.out.printf("It appears to be a very old key.%n");
               break;
            case CLOAK:
               System.out.printf("The cloak is black with a green satin lining.%n");
               break;
            case NOTE:
               System.out.printf("There's writing on it!%n");
               break;
            case COIN:
               System.out.printf("It's a $20 gold piece!%n");
               break;
            case TORCH:
               if (torchLit) 
               {
                  System.out.printf("It's lit.%n");
               } 
               else 
               {
                  System.out.printf("It's currently not lit.%n");
               }
               break;
            case ROCK:
               System.out.printf("It's a rock.%n");
               break;
            case MEAT:
               System.out.printf("It's filet mignon!%n");
               break;
            case PHONE:
               System.out.printf("It appears to have a note on the back:%n");
               System.out.printf("\"If found, please return to Student Life.\"%n");
               break;
            case ASHES:
               System.out.printf("This is from the cloak you burned up earlier.%n");
               break;
            case SOOT:
               System.out.printf("This is from the note you destroyed.%n");
               break;
            default:
               System.out.printf("I can't examine that.%n");
               break;
         }
      } 
      else 
      {
         System.out.printf("I can't examine that.%n");
      }
   }

   public static boolean eatObject(int objectNum, int currentRoom, boolean torchLit) 
   {
      if (objectIsAvailable(objectNum, currentRoom)) 
      {
         switch (objectNum) 
         {
            case KEY:
               System.out.printf("I don't think it would taste good.%n");
               break;
            case CLOAK:
               System.out.printf("You choke down the cloak and die.%n");
               return true;
            case NOTE:
               System.out.printf("There's writing on it!%n");
               break;
            case COIN:
               System.out.printf("It's a $20 gold piece! But ok ...%n");
               OBJ_LOCATION[COIN] = GONE_LOCATION;
               break;
            case TORCH:
               if (torchLit) 
               {
                  System.out.printf("It's lit.%n");
               } 
               else 
               {
                  System.out.printf("It's currently not lit.%n");
               }
               break;
            case ROCK:
               System.out.printf("It's a rock.%n");
               break;
            case MEAT:
               System.out.printf("Yum. Raw meat.%n");
               OBJ_LOCATION[MEAT] = GONE_LOCATION;
               break;
            case STEAK:
               System.out.printf("The steak turns out to be delicious!%n");
               OBJ_LOCATION[STEAK] = GONE_LOCATION;
               break;
            default:
               System.out.printf("I can't eat that.%n");
               break;
         }
      } 
      else 
      {
         System.out.printf("I can't eat that.%n");
      }
      return false;
   }

   public static boolean igniteObject(int objectNum, int currentRoom, boolean torchLit) 
   {
      System.out.printf("This is IGNITE.%n");
      if (objectIsAvailable(objectNum, currentRoom) && objectIsAvailable(MATCH, currentRoom)) 
      {
         switch (objectNum) 
         {
            case CLOAK:
               System.out.printf("The cloak burns slowly into ashes.%n");
               OBJ_LOCATION[CLOAK] = GONE_LOCATION;
               OBJ_LOCATION[ASHES] = currentRoom;
               break;
            case NOTE:
               System.out.printf("The note burns quickly into soot.%n");
               OBJ_LOCATION[NOTE] = GONE_LOCATION;
               OBJ_LOCATION[SOOT] = currentRoom;
               break;
            case TORCH:
               System.out.printf("You have successfully lit the torch!%n");
               torchLit = true;
               break;
            case MEAT:
               System.out.printf("With much patience, the match turns the meat into a nice steak.%n");
               OBJ_LOCATION[MEAT] = GONE_LOCATION;
               OBJ_LOCATION[STEAK] = INV_LOCATION;
               break;
            default:
               System.out.printf("The match burns with a beautiful light -- and then goes out.%n");
               break;
         }
         System.out.printf("The torch burns brightly at your feet.%n");
      } 
      else 
      {
         System.out.printf("I can't ignite that.%n");
      }
      return torchLit;
   }

   public static boolean isItemInRoom(int objectNum, int room) 
   {
      return OBJ_LOCATION[objectNum] == room;
   }

   public static boolean isItemInInv(int objectNum) 
   {
      return OBJ_LOCATION[objectNum] == INV_LOCATION;
   }

   public static boolean objectIsAvailable(int objectNum, int currentRoom) 
   {
      return objectNum != NOT_FOUND && (isItemInRoom(objectNum, currentRoom) || isItemInInv(objectNum));
   }
}

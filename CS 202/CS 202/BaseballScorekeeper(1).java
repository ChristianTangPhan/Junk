/* ==================================================================
 * Name: [SURNAME], [FORENAME]
 * ID #: [PCC ID]
 * Section: CS 202-[SECTION]
 * Program: [NUMBER]
 *
 * REPLACE THIS TEXT WITH A DESCRIPTION OF YOUR PROGRAM
 * ================================================================== */
import java.util.Scanner;

public class BaseballScorekeeper
{
   public static final Scanner KEYBOARD = new Scanner(System.in);
   public static final String  DASHES          = "=".repeat(75);
   // REMOVE THESE COMMENTS BEFORE SUBMITTING.
   // What constant is needed to state how many innings there are in a baseball game?

   public static void main(String[] args)
   {
      String homeTeamName,
             visitorTeamName;
             
      // REMOVE THESE COMMENTS BEFORE SUBMITTING.
      // What method needs to be called to let the user know what this program does?
      
      visitorTeamName = getTeamName("visitor");
      homeTeamName    = getTeamName("home");
      
      // REMOVE THESE COMMENTS BEFORE SUBMITTING.
      // What method will keep score for all the innings of a baseball game?
      
      return;
   }

   public static void displayInstructions()
   {
      // REMOVE THESE COMMENTS BEFORE SUBMITTING.
      // What should the user be told when the program first starts running?
      
      return;
   }
   
   // Obtain the team's name.
   public static String getTeamName(String teamType)
   {
      String teamName;
      
      do 
      {
         System.out.printf("Please enter the name of the %s team: ", teamType);
         teamName = KEYBOARD.nextLine();
         
         if (teamName.length() == 0)
            System.out.printf("The team name must not be empty.%n");
      } while (teamName.length() == 0);
      
      return teamName;
   }

   public static void trackAllInnings(String visitorTeamName, String homeTeamName)
   {
      // REMOVE THESE COMMENTS BEFORE SUBMITTING.
      // What variables will be used to keep track of each team's total score?
            
      for (int currentInning = 1; currentInning <= FINAL_INNING; currentInning++) 
      {
         displayHeading("Starting Inning " + currentInning);

         // REMOVE THESE COMMENTS BEFORE SUBMITTING.
         // Which team do we need to get the current score for and ...
         // How do we keep a running total of that team's current score?

         if (currentInning != FINAL_INNING || homeTeamScore <= visitorTeamScore)
         {
            // REMOVE THESE COMMENTS BEFORE SUBMITTING.
            // Which team do we need to get the current score for and ...
            // How do we keep a running total of that team's current score?
         }
         
         reportEndOfInning(visitorTeamName, visitorTeamScore, homeTeamName, homeTeamScore);
      }
      
      reportEndOfGame(visitorTeamName, visitorTeamScore, homeTeamName, homeTeamScore);
      
      return;
   }

   // Produce a heading
   public static void displayHeading(String heading)
   {
      System.out.printf("\n%s\n%s\n%s\n", DASHES, heading, DASHES);
      
      return;
   }
   
   // Get a team's score.
   public static int getTeamScore(String teamName)
   {
      int runs;
   
      do
      {
         System.out.printf("\n\nHow many runs did the %s team complete? ", teamName);
         runs = KEYBOARD.nextInt();
         if (runs < 0)
         System.out.printf("\nA team cannot complete negative runs!\n");
      } while (runs < 0);
      
      return runs;
   }

   public static void reportEndOfInning(String visitorTeamName, int visitorTeamScore,
                                        String homeTeamName, int homeTeamScore)
   {
      displayHeading("End of inning scores");

      // REMOVE THESE COMMENTS BEFORE SUBMITTING.
      // What does the user need to know at the end of each baseball inning?
      
      return;
   }

   public static void reportEndOfGame(String visitorTeamName, int visitorTeamScore,
                                      String homeTeamName, int homeTeamScore)
   {
      displayHeading("Conclusion");
      
      // REMOVE THESE COMMENTS BEFORE SUBMITTING.
      // What should be displayed when visitorTeamScore > homeTeamScore?
      // What should be displayed when homeTeamScore > visitorTeamScore?
      // What should be displayed when neither of the previous conditions are true?
      
      return;
   }
}

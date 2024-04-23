/* ==================================================================
 * Name: Phan, Christian
 * ID #: 150311
 * Section: CS 202-4
 * Program: 9
 *
 * This program keeps track of baseball scores and innings.
 * ================================================================== */
import java.util.Scanner;

public class BaseballScorekeeper
{
   public static final Scanner KEYBOARD      = new Scanner(System.in);
   public static final String  DASHES        = "=".repeat(75);
   public static final int     FINAL_INNING  = 9;

   public static void main(String[] args)
   {
      String homeTeamName,
             visitorTeamName;
      int    trackAllInnings;
             
      displayInstructions();
      
      visitorTeamName = getTeamName("visitor");
      homeTeamName    = getTeamName("home");
      
      trackAllInnings(visitorTeamName, homeTeamName);
      
      return;
   }

   public static void displayInstructions()
   {
      System.out.printf("\nThis program is a baseball scorekeeper\n");
      System.out.printf("that keeps tracks of total runs\n");
      System.out.printf("and announces a winner!!\n\n");
      
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
      int homeTeamScore = 0,
          visitorTeamScore = 0;
            
      for (int currentInning = 1; currentInning <= FINAL_INNING; currentInning++) 
      {
         displayHeading("Starting Inning " + currentInning);

         visitorTeamScore = visitorTeamScore + 
                            getTeamScore(visitorTeamName);    

         if (currentInning != FINAL_INNING || homeTeamScore <= visitorTeamScore)
         {
            homeTeamScore = homeTeamScore + getTeamScore(homeTeamName); 
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

      System.out.printf("%s %d total run(s)\n", visitorTeamName, 
                                                visitorTeamScore);
      System.out.printf("%s %d total run(s)\n", homeTeamName, 
                                                homeTeamScore);
      
      return;
   }

   public static void reportEndOfGame(String visitorTeamName, int visitorTeamScore,
                                      String homeTeamName, int homeTeamScore)
   {
      displayHeading("Conclusion");
      
      if (visitorTeamScore > homeTeamScore)
      {
         System.out.printf("\nThe %s team wins!!!\n", visitorTeamName);
      }
      else if (homeTeamScore > visitorTeamScore)
      {
         System.out.printf("\nThe %s team wins!!!\n", homeTeamName);
      }
      else
      {
         System.out.printf("Seems like it was a tie\n");
      }
      
      return;
   }
}

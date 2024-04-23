# ==================================================================
# Name: Dudwen
# Program: Turn-Based Fighting Template
# ==================================================================
import random

# Global constants and variables
PUNCH = 0
KICK = 1
CHARGE = 2
RUN = 3
BLOCK = 4
INFO = 5
HELP = 6
QUIT = 7

COUNTER_CHANCE = 4
HEAL = 10
STUN_CHANCE = 4
KICK_RATIO = 2
MAX_CHARGE = 3
MULTIPLIER_RATE = 2
STARTING_DAMAGE = 15
STARTING_DEFENCE = 2
STARTING_HEALTH = 100
STARTING_MULTIPLIER = 1
TALLY = 3

NOT_FOUND = -1

COMMANDS = [
   "punch",
   "kick",  
   "charge",
   "run",   
   "block", 
   "info",  
   "help",  
   "quit"   
           ]
           
PLAYERS = [0, 1]
OPPOSITION = [1, 0]

quitGame = False
playerOneBlock = False
playerTwoBlock = False

playerOneTally = 0
playerOneDamage = 0
playerOneHealth = STARTING_HEALTH
playerOneMultiplier = STARTING_MULTIPLIER

playerTwoTally = 0
playerTwoDamage = 0
playerTwoHealth = STARTING_HEALTH
playerTwoMultiplier = STARTING_MULTIPLIER

playerBlock = [playerOneBlock, playerTwoBlock]
playerTally = [playerOneTally, playerTwoTally]
playerDamage = [playerOneDamage, playerTwoDamage]
playerHealth = [playerOneHealth, playerTwoHealth]
playerMultiplier = [playerOneMultiplier, playerTwoMultiplier]

def displayInstructions():
   print(f"\nTurn-Based FIGHTING!!!")
   print(f"created by Dudwen")
   print(f"(if you need help")
   print(f"type \"help\" then hit enter)")
   print(f"FIGHT!!!")

def hit(playerNumber,opposition, playerHealth, playerMultiplier, playerBlock, kick):
   damage = random.randrange(STARTING_DAMAGE) * playerMultiplier[playerNumber]
   if kick == True:
      damage = damage // KICK_RATIO
   if bool(playerBlock[playerNumber]) == True:
      damage = damage // STARTING_DEFENCE
      
   print(f"You did {damage} damage.")
   print(f"Player {opposition + 1} has {int(playerHealth[opposition]) - damage} health")
      
   return damage
   
def charge(playerNumber, playerMultiplier):
   charge = playerMultiplier[playerNumber] * MULTIPLIER_RATE
   print(f"Your Damage is now multiplied by {charge}")
   
   return charge
   
def block(playerNumber, opposition, playerHealth, playerDamage, playerTally):
   defence = True
   counter = random.randrange(COUNTER_CHANCE)
   damage = int(playerDamage[opposition])
   
   if counter + 1 == COUNTER_CHANCE and damage > 0:
      playerHealth[opposition] = playerHealth[opposition] - damage
      print(f"You counter attacked for {damage}")
      playerDamage[playerNumber] = damage
   
   playerTally[playerNumber] = TALLY
   print(f"Your damage is cut in half for the next {playerTally[playerNumber]} turns")
   
   return defence
         
def run(playerNumber, playerHealth):
   healing = random.randrange(HEAL)
   print(f"You catch your breath")
   overhealCheck = playerHealth[playerNumber] + healing
   if overhealCheck > STARTING_HEALTH:
      print(f"You healed to max HP")
      healing = STARTING_HEALTH - playerHealth[playerNumber]
      playerHealth[playerNumber] = STARTING_HEALTH
   print(f"Healed +{healing} health")
   
   return playerHealth[playerNumber]
   
def showHelp(userInput, commandNum):
   print(f"\nThese are the Commands")
   index = 0
   while index < len(COMMANDS):
      print(f"   {COMMANDS[index]}")
      index += 1
   print(f"\nWhich command would you like help with")
   userInput = input("")
   commandNum = getCommand(userInput)
   if commandNum == PUNCH:
      print(f"Does 0-{STARTING_DAMAGE} damage")
   elif commandNum == KICK:
      print(f"Does 0-{STARTING_DAMAGE // KICK_RATIO} damage")
      print(f"1/{STUN_CHANCE + 1} chance to stun")
   elif commandNum == CHARGE:
      print(f"Exponentially Multiplies damage\n")
      print(f"Caps at x{MULTIPLIER_RATE ** MAX_CHARGE} ({MAX_CHARGE} charges)")
      print(f"RESETS AFTER HIT")
   elif commandNum == RUN:
      print(f"Heals 0-{HEAL} health")
   elif commandNum == BLOCK:
      print(f"Take half damage")
      print(f"lasts for {TALLY} turns (Tally)")
      print(f"1/{COUNTER_CHANCE} chance to deal opponents last hit")
   elif commandNum == INFO:
      print(f"Shows all stats")
   elif commandNum == HELP:
      print(f"Shows Commands")
   elif commandNum == QUIT:
      print(f"Exits the game")
   else:
      print(f"huh?\n")
   
def showInfo(playerTally, playerHealth, playerMultiplier):

   print(f"\nStats:")
   index = 0
   while index < len(PLAYERS):
      try:
         print(f" Player {PLAYERS[index] + 1}:")
         print(f"    Health - {playerHealth[PLAYERS[index]]}")
         print(f"    Multiplier - {playerMultiplier[PLAYERS[index]]}")
         print(f"    Defence Tally - {playerTally[PLAYERS[index]]}")
         index += 1
      except:
         break

def getCommand(theInput):
   theCommand = theInput
   index = 0
   while index < len(COMMANDS):
      try:
         if COMMANDS[index] == theInput.lower():
            return index
      except:
         break
      index += 1
   return NOT_FOUND
   
displayInstructions()
while quitGame == False:
   for playerNumber in PLAYERS: 
      opposition = OPPOSITION[playerNumber]
      endturn = False
      kick = False
     
      while endturn == False and quitGame == False:
         print(f"\nPlayer {playerNumber + 1}'s turn")
         userInput = input("")
         commandNum = getCommand(userInput)
         if playerTally[playerNumber] > 0:
            playerTally[playerNumber] -= 1
         else:
            playerBlock[playerNumber] = False
         if commandNum == PUNCH:
            playerDamage[playerNumber] = hit(playerNumber, opposition, playerHealth, playerMultiplier, playerBlock, kick)
            playerHealth[opposition] = playerHealth[opposition] - playerDamage[playerNumber]
            playerMultiplier[playerNumber] = STARTING_MULTIPLIER
            endturn = True
         elif commandNum == KICK:
            kick = True
            playerDamage[playerNumber] = hit(playerNumber, opposition, playerHealth, playerMultiplier, playerBlock, kick)
            playerHealth[opposition] = playerHealth[opposition] - playerDamage[playerNumber]
            stun = random.randrange(STUN_CHANCE)
            if stun + 1 == STUN_CHANCE:
               print(f"STUNNED")
               endturn = False
            else:
               endturn = True
            playerMultiplier[playerNumber] =  STARTING_MULTIPLIER
         elif commandNum == CHARGE:
            if playerMultiplier[playerNumber] >= MULTIPLIER_RATE ** MAX_CHARGE:
               playerMultiplier[playerNumber] = MULTIPLIER_RATE ** MAX_CHARGE
               print(f"You are already at max charge")
               endturn = False
            else:
               playerMultiplier[playerNumber] = charge(playerNumber, playerMultiplier)
               endturn = True
         elif commandNum == RUN:
            if playerHealth[playerNumber] >= STARTING_HEALTH:
               playerHealth[playerNumber] = STARTING_HEALTH
               print(f"You are at already max health")
               endturn = False
            else:
               playerHealth[playerNumber] = run(playerNumber, playerHealth)
               endturn = True
         elif commandNum == BLOCK:
            playerBlock[playerNumber] = block(playerNumber, opposition, playerHealth, playerDamage, playerTally)
            endturn = True
         elif commandNum == INFO:
            showInfo(playerTally, playerHealth, playerMultiplier)
            endturn = False
         elif commandNum == HELP:
            showHelp(userInput, commandNum)
            endturn = False
         elif commandNum == QUIT:
            quitGame = True
            endturn = True
         else:
            print(f"ummm, no")
            endturn = False
      if playerHealth[opposition] <= 0:
         print(f"\nKNOCK OUT!!!")
         print(f"Player {opposition + 1} wins")
         quitGame = True
print(f"\nTHANKS FOR PLAYING!!!\n")

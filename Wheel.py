"""
====================================================================
This program creates a list for a randomization wheel for all the
possible games to play based on the amount of players and who has
which game
    - Dudwen
====================================================================
"""

"""
--------------------------------------------------------------------
Declaration
--------------------------------------------------------------------
"""

#Initializes players
cavey, deeswa, thien, dudwen, deft = False, False, False, False, False
ID = ["cavey", "deeswa", "thien", "dudwen", "deft"]

#Other Initializations
MIN = 2
MAX = 5
lobbySize = 0
online = 0
quit = False

#The Game List
gameList = ["Fortnite","Osu","Fall Guys","Warframe","Brawlhalla","Business Tour","Crab game",
            "Drunken Wrestlers 2","Fps Chess", "Garry's Mod","Terraria","Dauntless","Muck","Phasmophobia",
            "Darza's Dominion","Eldin Ring","T Mod Loader","Ultimate Chicken Horse","Rocket League","Knockout City","Ark Survival",
            "Apex","Valorant","League of Legends","Diep","Roblox","Overwatch 2","Dead by Daylight",
            "Minecraft","Party games","Moomoo.io","Mope.io","Shellshock","Spiltgate","Rouge Company",
            "Lethal Company","Rainbow Six Siege","Destiny 2","Bluestacks","Pixel Gun","Rainworld","Itchi.io",
            "Grabity","Astroneer","Rounds", "Among Us"]

#The Game Status Options
nah = 0
yes = 1
d_u = 2 #Needs a download or update
g_s = 3 #Needs a specific player to play

twoPlayer   = [9, 33]
threePlayer = [20, 22, 36]
fourPlayer  = [3, 4, 5, 6, 8, 12, 14, 18, 41, 43, 45]
fivePlayer  = [23, 24]
dudwenOnly  = [41]

"""
--------------------------------------------------------------------
QUESTIONS 
--------------------------------------------------------------------
"""
print("ALL POSSIBLE GAMES LIST!!!")
#Asks for amount of players online
while (lobbySize < MIN or lobbySize > MAX):
    lobbySize = (input("How many people playing (2-5): "))

    try:
        lobbySize = int(lobbySize)
    except ValueError:
        lobbySize = 0

    if (lobbySize < MIN or lobbySize > MAX):
       print("Out of Range\n")

#Asks if online are willing to wait for downloads or updates
choice = input("Are you willing to download or update if needed: ")

try:
    characterCheck = str(choice)
except ValueError:
    choice = "nah"

willing = choice.lower().startswith("y")
if (willing == True):
    print("Unready games will be added into this list")
    d_u = yes
print("")

#Drafting Players
while quit == False and online < lobbySize:
    print("1. Cavey")
    print("2. Deeswa")
    print("3. Thien")
    print("4. Dudwen")
    print("5. Deft")
    print("6. Thats all!")
    player = (input("Who is playing: "))
    
    try:
        player = str(player)
    except ValueError:
        pass

    if player == "1" or player.lower() == "cavey":
        if cavey == True:
            print("Cavey is already added\n")
            online -= 1
        else:
            cavey = True
            print("Cavey is added\n")
    elif player == "2" or player.lower() == "deeswa":
        if deeswa == player == "deeswa":
            print("Deeswa is already added\n")
            online -= 1
        else:
            deeswa = True
            print("Deeswa is added\n")
    elif player == "3" or player.lower() == "thien":
        if thien == True:
            print("thien is already added\n")
            online -= 1
        else:
            thien = True
            print("Thien is added\n")
    elif player == "4" or player.lower() == "dudwen":
        if dudwen == True:
            print("Dudwen is already added\n")
            online -= 1
        else:
            dudwen = True
            print("Dudwen is added\n")
    elif player == "5" or player.lower() == "deft":
        if deft == True:
            print("Deft is already added\n")
            online -= 1
    elif player == "6" or player.lower() == "quit":
        quit == True
    else:
        print("not an option\n")
        online -= 1
    online += 1

"""
--------------------------------------------------------------------
Database
--------------------------------------------------------------------
"""
# Order: Cavey, Deeswa, Thien, Dudwen, Deft
# Contains players status on specified games
database = [
    # 1. Fortnite
    [yes, yes, yes, yes, d_u],
    # 2. Osu
    [yes, yes, nah, yes, d_u],
    # 3. Fall Guys
    [yes, yes, d_u, yes, d_u],
    # 4. Warframe
    [yes, yes, nah, nah, d_u],
    # 5. Brawlhalla
    [nah, yes, d_u, yes, d_u],
    # 6. Business Tour
    [yes, yes, yes, yes, d_u],
    # 7. Crab Game
    [yes, yes, d_u, yes, nah],
    # 8. Drunken Wrestlers 2
    [yes, yes, d_u, yes, d_u],
    # 9. Fps Chess
    [yes, yes, d_u, yes, yes],
    # 10. Garry's Mod
    [yes, yes, d_u, yes, d_u],
    # 11. Terraria
    [yes, yes, d_u, yes, yes],
    # 12. Dauntless
    [yes, yes, d_u, yes, nah],
    # 13. Muck
    [yes, yes, yes, yes, d_u],
    # 14. Phasmophobia
    [yes, yes, d_u, yes, d_u],
    # 15. Darza's Dominion
    [d_u, yes, nah, yes, nah],
    # 16. Eldin Ring
    [yes, yes, d_u, d_u, d_u],
    # 17. T Mod Loader
    [yes, yes, nah, nah, yes],
    # 18. Ultimate Chicken Horse
    [yes, yes, nah, yes, nah],
    # 19. Rocket League
    [yes, yes, d_u, d_u, nah],
    # 20. Knockout City
    [d_u, yes, d_u, d_u, d_u],
    # 21. Ark Survival
    [d_u, yes, nah, d_u, nah],
    # 22. Apex
    [d_u, yes, nah, d_u, d_u],
    # 23. Valorant
    [yes, yes, d_u, yes, yes],
    # 24. League of Legends
    [yes, yes, d_u, yes, yes],
    # 25. Diep.io
    [yes, yes, yes, yes, yes],
    # 26. Roblox
    [yes, yes, yes, yes, nah],
    # 27. Overwatch 2
    [nah, yes, nah, d_u, nah],
    # 28. Dead by Daylight
    [yes, yes, nah, yes, nah],
    # 29. Minecraft
    [yes, yes, yes, yes, nah],
    # 30. Party Games (Discord games or JKLM or Spyfall)
    [yes, yes, yes, yes, yes],
    # 31. Moomoo.io
    [yes, yes, yes, yes, yes],
    # 32. Mope.io
    [yes, yes, yes, yes, yes],
    # 33. Shellshock
    [yes, yes, yes, yes, yes],
    # 34. Spiltgate
    [d_u, yes, nah, d_u, d_u],
    # 35. Lethal Company
    [d_u, yes, yes, yes, yes],
    # 36. Rouge Company
    [d_u, yes, nah, d_u, d_u],
    # 37. Rainbow Six Siege
    [yes, yes, yes, yes, yes],
    # 38. Destiny 2
    [d_u, d_u, d_u, d_u, d_u],
    # 39. Bluestacks
    [yes, yes, d_u, d_u, d_u],
    # 40. Pixel Gun
    [yes, yes, nah, yes, yes],
    # 41. Rainworld
    [yes, nah, nah, yes, yes],
    # 42. Itchi.io
    [yes, yes, yes, yes, yes],
    # 43. Grabity
    [yes, d_u, d_u, yes, yes],
    # 44. Astroneer
    [yes, yes, nah, yes, nah],
    # 45. Rounds
    [yes, yes, yes, yes, yes],
    # 46. Among Us
    [d_u, yes, yes, yes, yes],
]

"""
--------------------------------------------------------------------
CALCUATIONS
--------------------------------------------------------------------
"""
#Removes offline from list
if cavey == False:
    for reset in range(len(database)):
        database[reset][ID.index("cavey")] = yes
if deeswa == False:
    for reset in range(len(database)):
        database[reset][ID.index("deeswa")] = yes
if thien == False:
    for reset in range(len(database)):
        database[reset][ID.index("thien")] = yes
if dudwen == False:
    for reset in range(len(database)):
        database[reset][ID.index("dudwen")] = yes
if deft == False:
    for reset in range(len(database)):
        database[reset][ID.index("deft")] = yes

#Needs Dudwen to play
if dudwen == False:
    for players in range(len(ID)):
        for remove in range(len(dudwenOnly)):
            database[dudwenOnly[remove]-1][players] = nah

#Removes 2 player games
if online > 2:
    for players in range(len(ID)):
        for remove in range(len(twoPlayer)):
            database[twoPlayer[remove]-1][players] = nah
"""
#Removes 3 player games
if online > 3:
    for players in range(len(ID)):
        for remove in range(len(threePlayer)):
            database[threePlayer[remove]-1][players] = nah
"""
#Removes 4 player games
if online > 4:
    for players in range(len(ID)):
        for remove in range(len(fourPlayer)):
            database[fourPlayer[remove]-1][players] = nah
"""
#Removes 5 player games
if online > 5:
    for players in range(len(ID)):
        for remove in range(len(fivePlayer)):
            database[fivePlayer[remove]-1][players] = nah
"""

"""
--------------------------------------------------------------------
Display
--------------------------------------------------------------------
"""
#Prints all possible games list
print("List of possible games")
for games in range(len(database)):
    if (database[games][ID.index("cavey")] == 
        database[games][ID.index("deeswa")] == 
        database[games][ID.index("thien")] == 
        database[games][ID.index("dudwen")] == 
        database[games][ID.index("deft")] == yes):
        print(gameList[games])

"""
====================================================================
This program creates a list for a randomization wheel for all the
possible games to play based on the amount of players and who has
which game
    - Dudwen
====================================================================
"""

print("=============================")
print("= LIST ALL GAMES PROGRAM!!! =")
print("=============================")

"""
--------------------------------------------------------------------
Declaration
--------------------------------------------------------------------
"""
#Initializes players
ID = ["cavey", "deeswa", "thien", "dudwen", "deft"]
status = {players: False for players in ID}

#Other Initializations
online = 0
quit = False

#The Game List
gameList = ["Fortnite","Osu","Fall Guys","Warframe","Brawlhalla","Business Tour","Crab game",
            "Drunken Wrestlers 2","Fps Chess", "Garry's Mod","Terraria","Dauntless","Muck","Phasmophobia",
            "Darza's Dominion","Eldin Ring","T Mod Loader","Ultimate Chicken Horse","Rocket League","Knockout City","Ark Survival",
            "Apex","Valorant","League of Legends","Diep","Roblox","Overwatch 2","Dead by Daylight",
            "Minecraft","Party games","Moomoo.io","Mope.io","Shellshock","Spiltgate","Rouge Company",
            "Lethal Company","Rainbow Six Siege","Destiny 2","Bluestacks","Pixel Gun","Rainworld","Itchi.io",
            "Grabity","Astroneer","Rounds", "Among Us", "One Arm Robber"]

#The Game Status Options
nah = 0
yes = 1
d_u = 2 #Needs a download or update
own = 3 #Needs a specific player to play

twoPlayer   = [gameList.index("Fps Chess"), gameList.index("Shellshock")]
threePlayer = [gameList.index("Knockout City"), gameList.index("Apex Legends"), gameList.index("Rouge Company")]
fourPlayer  = [gameList.index("Fall Guys"), gameList.index("Warframe"), gameList.index("Brawlhalla"), gameList.index("Business Tour"), 
               gameList.index("Drunken Wrestlers 2"), gameList.index("Dauntless"), gameList.index("Phasmophobia"), gameList.index("T Mod Loader"), 
               gameList.index("Rainworld"), gameList.index("Grabity"), gameList.index("Rounds"), gameList.index("One Arm Robber")]
fivePlayer  = [gameList.index("Valorant"), gameList.index("League of Legends"), gameList.index("Overwatch 2"), gameList.index("Dead by Daylight"), 
               gameList.index("Rainbow Six Siege")]

"""
--------------------------------------------------------------------
Questions
--------------------------------------------------------------------
"""
#Drafts players
while quit == False:

    #Checks if everyone in list is already added
    falseCheck = True
    for players in range(len(ID)):
        if status[ID[players]] == False:
            falseCheck = False
    if falseCheck == False:
        quit = False
    else:
        quit = True

    if quit == False:
        print("\n========== MENU ==========")
        print("1. Cavey")
        print("2. Deeswa")
        print("3. Thien")
        print("4. Dudwen")
        print("5. Deft")
        print("6. Who's in the -party-?")
        print("7. Reset party")
        print("8. Thats all!")
        player = (input("\nWho is playing: "))
        player = str(player)

        if player == "1" or player.lower() == "cavey":
            if status["cavey"] == True:
                print("\n-- Cavey is already added --")
            else:
                status["cavey"] = True
                print("\n-- Cavey is added --")
                online += 1
        
        elif player == "2" or player.lower() == "deeswa":
            if status["deeswa"] == True:
                print("\n-- Deeswa is already added --")
            else:
                status["deeswa"] = True
                print("\n-- Deeswa is added --")
                online += 1
        
        elif player == "3" or player.lower() == "thien":
            if status["thien"] == True:
                print("\n-- thien is already added --")
            else:
                status["thien"] = True
                print("\n-- Thien is added --")
                online += 1
        
        elif player == "4" or player.lower() == "dudwen":
            if status["dudwen"] == True:
                print("\n-- Dudwen is already added --")
            else:
                status["dudwen"] = True
                print("\n-- Dudwen is added --")
                online += 1
        
        elif player == "5" or player.lower() == "deft":
            if status["deft"] == True:
                print("\n-- Deft is already added --")
            else:
                status["deft"] = True
                print("\n-- Deft is added --")
                online += 1
        
        elif player == "6" or player.lower() == "party":
            print("\n== These players are in the party ==")
            if online == 0:
                print("No one")
            elif online > 0:
                for players in range(len(ID)):
                    if status[ID[players]] == True:
                        print(ID[players].capitalize(), end = ' ') 
            else:
                print("\n\nhow did you break the program this bad...")
            print("")
        
        elif player == "7" or player.lower() == "reset":
            for players in range(len(ID)):
                status[ID[players]] = False
            print("\n<< Party is reset >>")
            online = 0
        
        elif player == "8" or player.lower() == "quit":
            if online < 2:
                print("\n!! Not enough !!")
            else:
                quit = True
        else:
            print("\n!! Not option !!")

#Asks if online players are willing to wait for downloads or updates
choice = input("\nAre yall willing to download or update games: ")
characterCheck = str(choice)
willing = choice.lower().startswith("y")

if willing == True:
    print("<< Unready games added to list >>")
    d_u = yes

"""
--------------------------------------------------------------------
Database
--------------------------------------------------------------------
"""
# Order: Cavey, Deeswa, Thien, Dudwen, Deft
# Contains players option on each games
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
    # 47. One Arm Robber
    [yes, yes, yes, yes, yes],
]

"""
--------------------------------------------------------------------
Calculations
--------------------------------------------------------------------
"""
#Congrats if you can understand this (@_@)
for games in range(len(database)):
    for scan in range(len(database[games])):
        if database[games][scan] == own:
            if status[ID[scan]] == True:
                database[games][scan] = yes

#Removes offline players from list
if status["cavey"] == False:
    for remove in range(len(database)):
        database[remove][ID.index("cavey")] = yes
if status["deeswa"] == False:
    for remove in range(len(database)):
        database[remove][ID.index("deeswa")] = yes
if status["thien"] == False:
    for remove in range(len(database)):
        database[remove][ID.index("thien")] = yes
if status["dudwen"] == False:
    for remove in range(len(database)):
        database[remove][ID.index("dudwen")] = yes
if status["deft"] == False:
    for remove in range(len(database)):
        database[remove][ID.index("deft")] = yes

#Removes 2 player games
if online > 2:
    for players in range(len(ID)):
        for remove in range(len(twoPlayer)):
            database[twoPlayer[remove]][players] = nah
"""
#Removes 3 player games
if online > 3:
    for players in range(len(ID)):
        for remove in range(len(threePlayer)):
            database[threePlayer[remove]][players] = nah
"""
#Removes 4 player games
if online > 4:
    for players in range(len(ID)):
        for remove in range(len(fourPlayer)):
            database[fourPlayer[remove]][players] = nah
"""
#Removes 5 player games
if online > 5:
    for players in range(len(ID)):
        for remove in range(len(fivePlayer)):
            database[fivePlayer[remove]][players] = nah
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

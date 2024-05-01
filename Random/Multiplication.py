import random

quit = False
score = 0
difficulty = 1

print("Practice Math")

while not quit:
    numCheck = True
    num1 = random.randint(1, difficulty)
    num2 = random.randint(1, difficulty)
    
    print('\n', num1, '*' , num2, "= ", end='')
    answer = input()
    
    try:
        answer = int(answer)
    except ValueError:
        print("Please enter a valid integer.")
        numCheck = False
    
    if numCheck == True:
        if answer != (num1 * num2):
            quit = True
            if score < 10:
                print("Run it back!")
            if score >= 10:
                print("Not bad!")
            if score >= 100:
                print("YOU WIN!!!")
        else:
            score += 1
        
        if difficulty < 12:
            difficulty += 1

print("Final Score:", score)

import random

guess = int(input("number to guess (1-1000) : "))

hell = 1
heaven = 1000
while(guess >= 1 and guess <= 1000):
    compguess = random.randint(hell, heaven)
    print(f"is this the number {compguess}")
    ans = input("user : ")
    if ans == "kekecilan":
        hell = compguess
    elif ans == "kebesaran":
        heaven = compguess
    elif ans == "benar":
        break
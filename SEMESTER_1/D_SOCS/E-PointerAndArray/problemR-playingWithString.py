def playwithstring():
    string = input()
    numofchanges = int(input())
    if numofchanges == 0:
        print(f"Case #{i + 1}: {string}")
    else:
        for j in range(numofchanges):
            change = input().split()
            for k in range(len(string)):
                if string[k] == change[0]:
                    string = string.replace(string[k], change[1])
        print(f"Case #{i + 1}: {string}")
        
testcases = int(input())

for i in range(testcases):
    playwithstring()
        

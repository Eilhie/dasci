x = int(input())
for i in range(x):
    s = input()
    c = len(set(s))
    if(c % 2 == 0):
        print(f"Case #{i + 1}: Yay")
    else :
        print(f"Case #{i + 1}: Ewwww")
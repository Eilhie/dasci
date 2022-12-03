from cgi import test


testcases = int(input())

for i in range(testcases):
    length = int(input())

    arr = input().split()

    pick = input().split()
    print(f"Case #{i + 1} : ", end="")
    if int(arr[int(pick[0]) - 1]) > int(arr[int(pick[1]) - 1]):
        print("Bibi")
    elif int(arr[int(pick[0]) - 1]) < int(arr[int(pick[1]) - 1]):
        print("Lili")
    else:
        print("Draw")



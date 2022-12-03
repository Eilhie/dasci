number = list(map(int, input().split()))
pos1 = int(input())
pos2 = int(input())

number[pos1 - 1], number[pos2 - 1] = number[pos2 - 1], number[pos1 - 1]

print(number)
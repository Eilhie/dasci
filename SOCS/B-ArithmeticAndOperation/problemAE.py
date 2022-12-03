turn = int(input())

# total_atk = turn * 100 + 50 * (turn - 1)

total_atk = 0

for i in range(1,turn+1):
    atk = 100 + 50 * (i-1)
    total_atk += atk

print(total_atk)
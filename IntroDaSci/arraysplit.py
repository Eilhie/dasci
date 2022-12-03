list = list(map(int, input().split()))
k = int(input())

for i in range(k):
    x = list[0]
    for j in range(len(list) - 1):
        list[j] = list[j + 1]
    list[len(list) - 1] = x

print(list)
testcases = int(input())

for i in range(testcases):
    data = int(input())
    dataset = input().split()
    datatest = input().split()
    sum = 0
    for j in range(data):
        if not (int(dataset[j]) >= int(datatest[j])):
            sum += 1
    print(f"Case #{i + 1}: {sum}")
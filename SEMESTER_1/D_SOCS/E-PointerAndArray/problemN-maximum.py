testcases = int(input())

for i in range(testcases):
    len = int(input())

    arr = input().split()

    arr.sort(reverse=True)
    print(f"Case #{i + 1}: {int(arr[0]) + int(arr[1])}")

len = int(input())

arr = input().split()

testcases = int(input())
for i in range(testcases):
    a,b = input().split()
    sum = 0 
    for j in range(int(a)-1, int(b)):
        sum += int(arr[j])

    print(f"Case #{i+1}: {sum}")
def fibWord(n, a ,b):
    Sn_1 = a
    Sn = b
    tmp = ""
    for i in range(2, int(n) + 1):
        tmp = Sn
        Sn += Sn_1
        Sn_1 = tmp
    return Sn
 
testCases = int(input())
for i in range(testCases):
    n, a, b = input().split()
    print (f"Case #{i + 1}: {fibWord(n,a,b)}")
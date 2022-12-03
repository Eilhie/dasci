dict = input()

dict = eval(dict)

sum = 0
for i, j in enumerate(dict):
    sum += int(dict[j])

print(sum)
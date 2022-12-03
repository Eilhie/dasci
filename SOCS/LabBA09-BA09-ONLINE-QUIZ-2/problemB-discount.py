x,y = input().split()

result = (int(x) - int(y)) * 100 / int(x)

print("{:.2f}%".format(result))
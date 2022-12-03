import numpy as np

x = np.arange(10, 34)
y = x.reshape(8,3)

print(x)
print(y)

# y = np.array([[1,2,3,4], [5,6,7,8]])

a,b = np.shape(y)

for i in range(a):
    if i % 2 != 0:
        print(y[i])

for i in range(1, b+1):
    if i % 2 == 0:
        print(y[:,i-1])

arr = [i for i in range(1,9)]

for i in range(1, b + 1):
    if i % 2 == 0:
        for j in range(a):
            y[j][i - 1] = arr[j]

print(y)
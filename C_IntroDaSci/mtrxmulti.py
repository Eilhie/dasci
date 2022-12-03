import numpy as np

x = list(map(int, input().split()))
y = list(map(int, input().split()))

x = np.array(x)
y = np.array(y)
x = x.reshape(3,3)
y = y.reshape(3,3)

print(np.multiply(x,y))
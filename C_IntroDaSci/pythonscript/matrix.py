import numpy as np

x = np.arange(0,25)

print(x)

y = x.reshape(5,5)

print(y)

z = np.sum(y, axis=1)
print(z)

a = np.median(y, axis=0)
print(a)

b = np.mean(x)
print(int(b))

for i, d in enumerate(x):
    if d > b:
        print(d)
odd = 0
even = 0
for i, d in enumerate(x):
    if x[i] % 2 == 0:
        even += 1
    else:
        odd += 1

print("odd = ", odd, "\neven = ", even)
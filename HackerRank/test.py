import numpy as np

arr = [2, 1, 3, 1, 4, 2, 3, 2, 1]

arr = np.array(arr)

arr = np.linalg.inv(arr)

print(arr)
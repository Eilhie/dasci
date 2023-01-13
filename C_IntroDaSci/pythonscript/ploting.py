import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

def statistic(list, name):
    list = np.array(list)
    print("\n" + name)
    print(f"mean : {list.mean():.5f}")
    print(f"std  : {list.std():.5f}")
    print(f"min  : {list.min():.5f}")
    print(f"25%  : {np.percentile(list, 25):.5f}")
    print(f"50%  : {np.percentile(list, 50):.5f}")
    print(f"75%  : {np.percentile(list, 75):.5f}")
    print(f"max  : {list.max():.5f}")

def histogram(index, dataset1, dataset2, dataset3, name):
    start = index[0]
    end = index[-1]
    df = pd.DataFrame(list(zip(dataset1[start:end+1],dataset2[start:end+1],dataset3[start:end+1])), columns = ["sepallength", "sepalwidth", "petalwidth"])
    print(df)
    # plt.title(name)
    df[["sepallength", "sepalwidth", "petalwidth"]].hist()
    plt.show()
    
sepallength= [4.9, 4.7, 4.6, 5.0, 5.7, 6.3, 4.9, 6.6, 6.5, 6.4, 6.8, 5.7]
sepalwidth = [3.0, 3.2, 3.1, 3.6, 2.8, 3.3, 2.4, 2.9, 3.2, 2.7, 3.0, 2.5]
petallength= [1.4, 1.3, 1.5, 1.4, 4.5, 4.7, 3.3, 4.6, 5.1, 5.3, 5.5, 5.0]
petalwidth = [0.2, 0.2, 0.2, 0.2, 1.3, 1.6, 1.0, 1.3, 2.0, 1.9, 2.1, 2.0]
flowerclass = ["iris-setosa", "iris-setosa", "iris-setosa", "iris-setosa", "iris-versicolor", "iris-versicolor", "iris-versicolor", "iris-versicolor", "iris-virginica", "iris-virginica", "iris-virginica", "iris-virginica", ]

statistic(sepallength, "sepallength")
statistic(sepalwidth, "sepalwidth")
statistic(petalwidth, "petalwidth")

setosa = []
versicolor = []
virginica = []

for i in range(len(flowerclass)):
    if flowerclass[i] == "iris-setosa":
        setosa.append(i)
    elif flowerclass[i] == "iris-versicolor":
        versicolor.append(i)
    elif flowerclass[i] == "iris-virginica":
        virginica.append(i)

histogram(setosa, sepallength, sepalwidth, petallength, "setosa")
histogram(versicolor, sepallength, sepalwidth, petallength, "versicolor")
histogram(virginica, sepallength, sepalwidth, petallength, "virgini")

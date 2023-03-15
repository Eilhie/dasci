library(ggplot2)

head(iris)

summary(iris)

dim(iris)

str(iris)

sumMisVal = function(x){
  temp <- sum(is.na(x))
  return(temp)
}
sapply(X = iris,FUN = sumMisVal)

names(iris)

class(iris)

hist(x = iris$Sepal.Length, xlab = "Sepal Lenght", main = 
     "Histogram of Sepal Lenght of Iris Data")

hist(x = iris$Sepal.Width, xlab = "Sepal Width", main = 
     "Histogram of Sepal Width of Iris Data")

hist(x = iris$Petal.Length, xlab = "Petal Lenght", main = 
     "Histogram of Petal Lenght of Iris Data")
    
hist(x = iris$Petal.Width, xlab = "Petal Width", main = 
     "Histogram of Petal Width of Iris Data") 

cor(iris[, 1:4])
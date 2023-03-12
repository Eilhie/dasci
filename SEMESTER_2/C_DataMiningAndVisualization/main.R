#import library
library(tidyr)
library(dplyr)
library(ggplot2)

#EDA
#import dataset, replacing N/A value in dataset to NA, because R cannot read N/A as missing values.
df <- read.csv("vgsales.csv")
head(df)

#check summary of dataset
summary(df)

#check data dimension
dim(df)

#check variable name and type
str(df)

#check missing values
sumMisVal = function(x){
  temp <- sum(is.na(x))
  return(temp)
}
sapply(X = df,FUN = sumMisVal)

#drop missing values
df <- drop_na(df)

#drop unusable columns 
df <- subset(df,select = -c(Rank))


#make barplot for year x sales
vis1 <- table(df$Year,df$Global_Sales)


plot(x=df$Global_Sales, y=df$Year)



# install.packages("ggplot2")

# #import library
library(tidyr)
library(dplyr)
library(ggplot2)

# #EDA
# #import dataset, replacing N/A value in dataset to NA, because R cannot read N/A as missing values.
df <- read.csv("vgsales.csv")
head(df)

# #check summary of dataset
summary(df)

# #check data dimension
dim(df)

# #check variable name and type
str(df)

# #check missing values
sumMisVal = function(x){
  temp <- sum(is.na(x))
  return(temp)
}
sapply(X = df,FUN = sumMisVal)

#drop missing values
df <- drop_na(df)

# #drop unusable columns 
df <- subset(df,select = -c(Rank))

plot(x=df$Year, y=df$Global_Sales, xlab = "Year", ylab = "Global Sales", horiz = FALSE)


# Total number of records in dataframe
df %>% nrow()
#[1] 150
# Number of records per Group (count and tally are interchangeable)
ListOfPlatform <- df %>% group_by(Platform) %>% count()
ListOfPlatform = ListOfPlatform[order(ListOfPlatform$n, decreasing = TRUE),]
print(ListOfPlatform[order(ListOfPlatform$n, decreasing = TRUE), ])

ListOfGenre <- df %>% group_by(Genre) %>% count()
ListOfGenre = ListOfGenre[order(ListOfGenre$n, decreasing = TRUE),]
print(ListOfGenre[order(ListOfGenre$n, decreasing = TRUE), ])

# visualize
# Sales By region DONE
# most popular platform 
# most popular game
# most popular genre
# most popular publisher

ggplot(
  df,
  aes(y = Platform)
) + geom_bar()


#vis pelangi genre
ggplot(
  ListOfGenre, 
  aes(x = ListOfGenre$n, y = ListOfGenre$Genre, colour = ListOfGenre$Genre)
) + geom_point()

# ggplot(
#   df,
#   aes(x = Genre, fill = Platform)
# ) + geom_bar(position = position_dodge()) + facet_wrap(~Platform)

ggplot(
  df,
  aes(y = Genre, fill = Platform)
) + geom_bar()

ggplot(
  df,
  aes(y = Genre, fill = Platform)
) + geom_bar(position = position_dodge())

salesSum <- c(sum(df$NA_Sales), sum(df$EU_Sales), sum(df$JP_Sales), sum(df$Other_Sales), sum(df$Global_Sales))
salesSum

barplot(salesSum, names.arg = c("NA", "EU", "JP", "Other", "Global"))


PubVSales <- df %>% group_by(Publisher, Global_Sales) %>% count()

TotalSalesbyPublisher <- aggregate(Global_Sales ~ Publisher, PubVSales, sum) 

TotalSalesbyPublisher = TotalSalesbyPublisher[order(TotalSalesbyPublisher$Global_Sales, decreasing = TRUE), ]

head(TotalSalesbyPublisher)


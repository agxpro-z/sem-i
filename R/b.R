# Q2. The numbers given below are the first 10 days of rainfall amounts in 2000.
#     0.1, 0.6, 33.8, 1.9, 9.6, 4.3, 33.7, 0.3, 0.0, 0.1
#
#     Read them into a vector and
#   (a) Calculate them mean and standard deviation
#   (b) Which days saw the highest and lowest rainfall?

# Creating day vector
day <- c()
for (i in 1:10) {
    day[i] <- paste("Day ", i, sep="")
}

# rainfall vector
rainfall <- c(0.1, 0.6, 33.8, 1.9, 9.6, 4.3, 33.7, 0.3, 0.0, 0.1)

# Data frame for the data
rainfall_data <- data.frame(
    Day = day,
    Rainfall = rainfall
)

# Find max rainfall day
maxRainfall <- function(rainfall) {
    a <- rainfall[1]
    index <- 1
    for (i in 2:10) {
        if (a > rainfall[i]) {
        } else {
            a <- rainfall[i]
            index <- i
        }
    }
    return(paste("day ", index, " and is ", a, sep=""))
}

# Find min rainfall day
minRainfall <- function(rainfall) {
    a <- rainfall[1]
    index <- 1
    for (i in 2:10) {
        if (a < rainfall[i]) {
        } else {
            a <- rainfall[i]
            index <- i
        }
    }
    return(paste("day ", index, " and is ", a, sep=""))
}

# Print data frame
rainfall_data

# Mean of rainfall
str1 <- paste("\nMean rainfall is ", mean(rainfall), ".\n", sep="")
cat(str1)

# Standard deviation of rainfall
str2 <- paste("Standard deviation of the rainfall is ", round(sd(rainfall), digit = 3), ".\n", sep="")
cat(str2)

# Standard deviation of rainfall
str3 <- paste("Highest rainfall is on ", maxRainfall(rainfall), ".\n", sep="")
cat(str3)

# Standard deviation of rainfall
str4 <- paste("Lowest rainfall is on ", minRainfall(rainfall), ".\n", sep="")
cat(str4)

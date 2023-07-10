# Q1. Write an R Function to initialize a data frame for 10 people with column
#     as name and height (in cm). Use for loop to convert the height into meter.
#

# Name vector
name <- c("Abc", "Bcd", "Cde", "Def", "Efg", "Fgh", "Ghi", "Hij", "Ijk", "Jkl")

# Height vector
height <- c(158, 160, 147, 152, 146, 134, 176, 160, 155, 166)

# Data frame containing name and height
df <- data.frame("Name" = name, "Height" = height)

# Print data frame before modification
cat("Original Data Frame\n\n")
print(df)

# Using for loop to convert heights from cm to m\
for (x in 1:10) {
    df$Height[x] <- df$Height[x] / 100
}

# Printing new data frame
cat("\n\nData Frame after converting heights into meters\n\n")
print(df)

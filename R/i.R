#   Q9. Write a program in R to display the terms of harmonic series and their sum

# Vector of harmonic series of 10 elements
ap <- seq(1, 30, by = 3)
hp <- c()
for (x in seq_along(ap)) {
    # HP = 1/AP
    hp[x] <- round(1/ap[x], digit = 3)
}

# Harmonic series and their sum
print(hp)
str <- paste("\nSum of the harmonic series is", sum(hp), "\n")
cat(str)

# Q3. Construct a matrix with 10 rows and 10 columns all filled with random no.
#     between 0 and 1
#   (a) Calculate row means and column means.
#   (b) Sum of all diagonal values.
#   (c) Calculate the standard deviation across both.

# Matrix of 10x10 containing random values
m <- matrix(round(runif(100, 0, 1), digit = 3), nrow = 10)

# Vector containing mean of columns
col_means <- c()
for (x in 1:10) {
    col_means[x] <- mean(m[,x])
}

# Vector containing mean of rows
row_means <- c()
for (x in 1:10) {
    row_means[x] <- mean(m[x,])
}

# Sum of all diagonal values
diag_val <- c()
for (x in 1:10) {
    diag_val[x] <- m[x, x]
}

# Standard deviation col wise
col_sds <- c()
for (x in 1:10) {
    col_sds[x] <- sd(m[,x])
}

# Standard deviation row wise
row_sds <- c()
for (x in 1:10) {
    row_sds[x] <- sd(m[x,])
}

# Standard deviation of diagoanl
diag_sd <- sd(diag_val)

#
# Printing all data
#
cat("Matrix\n")
print(m)

cat("\nMean of columns\n")
for (x in 1:10) {
    str <- paste("Column", x, " mean ", round(col_means[x], digit = 3), "\n", sep="")
    cat(str)
}

cat("\nMean of rows\n")
for (x in 1:10) {
    str <- paste("Row", x, " mean ", round(row_means[x], digit = 3), "\n", sep="")
    cat(str)
}

cat("\nSD of columns\n")
for (x in 1:10) {
    str <- paste("Column", x, " standard deviation ", round(col_sds[x], digit = 3), "\n", sep="")
    cat(str)
}

cat("\nSD of rows\n")
for (x in 1:10) {
    str <- paste("Row", x, " standard deviation ", round(row_sds[x], digit = 3), "\n", sep="")
    cat(str)
}

str <- paste("\nSum of diagonal values is ", sum(diag_val), "\n", sep="")
cat(str)

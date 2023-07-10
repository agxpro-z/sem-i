# Q5. Assign values 'TRUE', 'FALSE', 'FALSE', 'TRUE' to logical vector 'X' and
#     'FALSE', 'TRUE', 'FALSE', 'TRUE' to logiacal vector 'Y'
#   (a) Perform element-wise logical AND and logical OR on X and Y
#   (b) Find logical AND and logical OR of X and Y

# Logical vector X
X <- c(TRUE, FALSE, FALSE, TRUE)

# Logical vector Y
Y <- c(FALSE, TRUE, FALSE, TRUE)

# Element-wise logical AND
X_AND_Y <- c()
for (x in 1:4) {
    X_AND_Y[x] <- X[x] & Y[x]
}

# Element-wise logical OR
X_OR_Y <- c()
for (x in 1:4) {
    X_OR_Y[x] <- X[x] | Y[x]
}

# Logical AND of X
AND_X <- TRUE
for (x in X) {
    AND_X <- AND_X & x
}

# Logical OR of X
OR_X <- FALSE
for (x in X) {
    OR_X <- OR_X | x
}

# Logical AND of Y
AND_Y <- TRUE
for (x in Y) {
    AND_Y <- AND_Y & x
}

# Logical OR of Y
OR_Y <- FALSE
for (x in Y) {
    OR_Y <- OR_Y | x
}

#
# Printing all data
#
cat("X\n")
print(X)

cat("\nY\n")
print(Y)

cat("\nX AND Y\n")
print(X_AND_Y)

cat("\nX OR Y\n")
print(X_OR_Y)

cat("\n AND X\n")
print(AND_X)

cat("\nOR X\n")
print(OR_X)

cat("\nAND Y\n")
print(AND_Y)

cat("\nOR Y\n")
print(OR_Y)

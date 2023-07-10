# Q6. Use the inbuilt dataset 'iris' and write R code for the following -
#     (a) To display the first few rows
#     (b) To display the structure of the iris dataset
#     (c) To display the value that lies at the intersection of row 3 and column 4
#     (d) To return values at the intersection of row 3 and columns from 1 to 4

# Load dataset 'iris'
data('iris')

# Display first few row
head(iris, n = 10)

# Structure of the dataset 'iris'
cat("\nIris Structure\n")
str(iris)

# Value at intersection of row 3 and column 4
cat("\nValue at row 3 and col 4\n")
iris[3, 4]

# Values at intersection of row 3 and column from 1 to 4
cat("\nVaules at row 3 and column 1 to 4\n")
for (x in 1:4) {
    print(iris[3, x])
}

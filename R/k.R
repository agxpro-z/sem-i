# Q11. Write an R program to create four vectors namely student ID, age, pointer,
#      department
#      (a) Merge the vectors into data frame studentData and print values using for
#          loop.
#      (b) Replace a value across the entire Data frame.
#      (c) Replace multiple values in a Data frame.
#          for (b) and (c) you can take other data frame having at least 2 columns
#          whose values lies in the same range.

# Vectors of student data
studentID <- 1:10
age <- as.integer(runif(10, 15, 20))
pointer <- round(runif(10, 6, 10), digits = 2)
department <- c("CSE", "CSE", "ECE", "ECE", "CSE", "CSE", "ECE", "ECE", "CSE", "CSE")

# Create data frame from the above vectors
studentData <- data.frame("ID" = studentID, "Age" = age, "Pointer" = pointer, "Department" = department)
print(studentData)

# Changing a value across entire data frame studentData
cat("\nModifying Age at row 5\n")
studentData$Age[5] = 19
cat("\n")
print(studentData)

# Vectors of similar student data for part (b) and (c)
studentID <- 1:10
age <- as.integer(runif(10, 15, 20))
pointer <- round(runif(10, 6, 10), digits = 2)
studentData1 <- data.frame("ID" = studentID, "Age" = age, "Pointer" = pointer)

# Replacing multiple values across data frame using data from similar data frame
cat("\nModifying multiple valus form similar dataset\n")
studentData$Age[5] = studentData1$Age[5]
studentData$Age[3] = studentData1$Age[3]
studentData$Age[7] = studentData1$Age[7]
studentData$Pointer[4] = studentData1$Pointer[4]
studentData$Pointer[9] = studentData1$Pointer[9]
cat("\n")

#
# Printing data frame studentData
#
print(studentData)

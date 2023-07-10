# Q4. Consider a problem where a user needs to group a set of people P who wants
#     to apply a loan at a bank. The main criterion for applying is the income of
#     the person.
#     Given I = (10000, 14000, 24000, 43000, 12323, 13414, 43212, 36000) which
#     corrosponds to the respective incomes of people in P. Group the people into
#     a low-risk customer or high-risk customer based on whether the customer's
#     Income is above 30000 (low-risk) or not (High risk)..

# Creating vector of People P
P <- c()
for (x in 1:8) {
    P[x] <- paste("Person", x, sep="")
}

# Creating income vector I using given values
I <- c(10000, 14000, 24000, 43000, 12323, 13414, 43212, 36000)

# Data frame of people and income
df <- data.frame("Person"=P, "Income"=I)

# Printing origianl Date Frame
cat("People Income Date\n")
print(df)

# Low risk people
cat("\nPeople with low risk\n")
low_risk_p <- df[df$Income > 30000, ]
print(low_risk_p)

# High risk people
cat("\nPeople with high risk\n")
high_risk_p <- df[df$Income <= 30000, ]
print(high_risk_p)

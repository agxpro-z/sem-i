# Q7. Given name of chemical = (c1, c2, c3, c4, c5, c6).
#     Amount produced = (90, 50, 100, 40, 20, 38)
#     Plot a pie chart with the initial angle of 180 degree and the color of
#     your choice.

# Chemical vector
Chemical <- c("C1", "C2", "C3", "C4", "C5", "C6")

# Amount produced
Amt_produced <- c(90, 50, 100, 40, 20, 38)

# Chemical with amount
chemical_amt <- c()
for (x in 1:6) {
    chemical_amt[x] <- paste(Chemical[x], Amt_produced[x])
}

# Plot pie chart
pie(Amt_produced, labels = chemical_amt, init.angle = 180, main = "Chemicals Produced in a day")

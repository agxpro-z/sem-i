# Q8. Write an R code using loop that prints() following sentences.
#     (a) #> "Four is greater than three"
#         #> "Four is greater than three"
#         #> "Four is greater than three"
#         #> "Next"
#         #> "Three is greater than two"
#         #> "Three is greater than two"
#         #> "Three is greater than two"

str1 <- "Four is greater than three"
str2 <- "Next"
str3 <- "Three is greater than two"

for (x in 1:7) {
    if (x < 4) {
        print(str1)
    } else if (x == 4) {
        print(str2)
    } else {
        print(str3)
    }
}

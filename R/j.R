# Q10. Write a nested loop, where the outer for() loop increments "a" 3 times and
#      the inner for() loop increments "b" 4 times. The break statement exits the
#      inner for() loop after 2 increments. The nested loop prints teh values of
#      viariables a and b.

a <- 10
b <- 12

for (x in 1:3) {
    for (y in 1:4) {
        if (y > 2) {
            break
        }
        a <- a + 1
        b <- b + 1
        stra <- paste("a", a)
        strb <- paste("b", b)
        print(stra)
        print(strb)
        cat("\n")
    }
}

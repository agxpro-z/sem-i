# Q12. Use the inbuilt dataset in R called the "cars" dataset.
#      (a) Using box plots demonstrate the Relation between the car's speed and the
#          distance taken to stop.
#      (b) Demonstrate the above question using a histogram.

# Load dataset "cars"
data('cars')

# Boxplot demostrating realation between cars speed and distance taken to stop
boxplot(cars$speed ~ cars$dist, ylab = "Speed", xlab = "Distance taken to stop", main = "Relation between cars speed and distance take to stop")

# Histogram demonstrating realation between cars speed and distance taken to stop
barplot(cars$dist, names.arg = cars$speed, xlab = "Speed", ylab = "Distance taken to stop", main = "Relation between cars speed and distance taken to stop")

cat("\014")
rm(list=ls())

### AUTO DATA
# Simple Linear Regression
lm.auto1 <- lm(mpg ~ horsepower, data=Auto)
summary(lm.auto1)
predict(lm.auto1,data.frame(horsepower=98), interval = 'confidence', level = 0.95)

# Visualization 1
attach(Auto)
plot(horsepower, mpg)
abline(lm.auto1, col="blue")
plot(lm.auto1)

# Visualization 2
pairs(Auto)
cor(Auto[ , sapply(Auto,is.numeric)])

# Multiple Linear Regression
lm.auto2 <- lm(mpg ~ .-name, data=Auto)
summary(lm.auto2)
plot(lm.auto2)

### CAR SEATS DATA
library(ISLR)
lm.carseat1 <- lm(Sales ~ Price + Urban + US, data = Carseats)
summary(lm.carseat1)

lm.carseat2 <- lm(Sales ~ Price + US, data = Carseats)
summary(lm.carseat2)
plot(lm.carseat2)
confint(lm.carseat2, level=0.95)

### Investigate coefficient
set.seed(1)
x = rnorm(100)
y = 2*x + rnorm(100)

lm1 <- lm(y ~ x + 0)
lm2 <- lm(x ~ y + 0)
summary(lm1)
summary(lm2)

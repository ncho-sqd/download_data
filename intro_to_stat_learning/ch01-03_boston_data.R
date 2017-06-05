cat("\014")
rm(list=ls())

#link Boston housing data
library(MASS)

#explore data
fix(Boston)
dim(Boston)
names(Boston)

#visualization
pairs(Boston)
plot(Boston$age, Boston$crim)
plot(Boston$dis, Boston$crim)
plot(Boston$rad, Boston$crim)
plot(Boston$tax, Boston$crim)
plot(Boston$ptratio, Boston$crim)

#function to plot histogram
plot_hist<-function(data,by){
  hist(data,breaks=seq(0,round(max(data)),by=by))
} 

par(mfrow=c(1,3))
plot_hist(Boston$crim,by=1)
plot_hist(Boston$tax,by=1)
plot_hist(Boston$ptratio,by=1)
par(mfrow=c(1,1))

#number of suburbs bordering charles river
length(which(Boston$chas==1))

#some additional checks
median(Boston$ptratio)
subset(Boston,medv==min(Boston$medv))
summary(subset(Boston,rm>7))
summary(subset(Boston,rm>8))

#single regression
lm.fit <- lm(medv~lstat, data = Boston)
summary(lm.fit)
names(lm.fit)
Boston$pred <- predict(lm.fit,Boston)

#plot again...
plot(Boston$lstat, Boston$medv)
abline(lm.fit, lwd=2, col="blue")

plot(predict(lm.fit),residuals(lm.fit))
plot(1:25,rep(1,25),pch=1:30)
plot(hatvalues(lm.fit)) #plots predicted against leverage stat
which.max(hatvalues(lm.fit))

#multiple regression
lm.fit2 <- lm(medv~.-age-indus, data=Boston)
summary(lm.fit2)

#vif(variance inflation factor)
install.packages("car")
library(car)
vif(lm.fit2)

#interaction term
lm.fit3 <- lm(medv~lstat*age, data=Boston)
summary(lm.fit3)
lm(medv~lstat+age+lstat:age, data=Boston) #equivalent to lm.fit3

#non-linear transformation of regressor
lm.fit4 <- lm(medv~lstat+I(lstat^2), data=Boston) #need to use I() function
summary(lm.fit4)
plot(lm.fit4)

lm.fit5 <- lm(medv ~ poly(lstat,5), data=Boston)
plot(lm.fit5)

#anova analysis
anova(lm.fit,lm.fit4)
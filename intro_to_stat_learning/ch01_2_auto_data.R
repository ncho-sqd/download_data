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

#number of suburbs bordering charles river
length(which(Boston$chas==1))

#some additional checks
median(Boston$ptratio)
subset(Boston,medv==min(Boston$medv))
summary(subset(Boston,rm>7))
summary(subset(Boston,rm>8))



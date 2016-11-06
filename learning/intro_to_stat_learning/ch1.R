#set working directory
setwd("C:/Users/Neil Cho/Desktop")

#import data
college<-read.csv("College.csv")

#view and summarize data
fix(college)
summary(college)

#convert first column to rowname
rownames(college)=college[,1]
college<-college[,-1]

#visualize
pairs(college[,1:10])

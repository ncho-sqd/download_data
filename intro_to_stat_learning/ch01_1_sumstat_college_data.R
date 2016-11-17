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

#newvars
Elite<-rep("No",nrow(college))
Elite[college$Top10perc>50]="Yes"
Elite<-as.factor(Elite)
college<-data.frame(college,Elite)

#visualize
pairs(college[,1:10])
plot(college$Private,college$Outstate)
plot(college$Elite,college$Outstate)

#visualization: histogram for all numeric vars
numeric_bool<-unname(sapply(college,is.numeric))
numeric_col<-names(college)[numeric_bool]
count<-length(numeric_col)
nrow<-ceiling(count/3)
par(mar=c(1,1,1,1)) #set margin to minimum for many plots
par(mfrow=c(nrow,2))
for (i in 1:count) {
  hist(college[,numeric_col[i]],main=numeric_col[i],xlab=numeric_col[i])
}





###R Learning Notes

# Data import
sales<-read.csv('sales.csv', stringsAsFactors=F) #stringsAsFactors prevents char being read as factor var

#Examine data
dim()
head()
names()  #lists all vars
str()  #lists all vars and datatype etc...
glimpse()  #dplyr function that is pretty much similar to str()
nrow()
ncol()

#Subsetting
my_df[1:5, ] # First 5 rows of my_df
my_df[, 4]   # Fourth column of my_df
my_df[-(1:5), ] # Omit first 5 rows of my_df
my_df[, -4]     # Omit fourth column of my_df

keep <- 5:(ncol(sales2) - 15)  #Subsetting certain columns only
sales3 <- sales2[, keep]

#Editing variables
separate(sales3, event_date_time,
                   c("event_dt", "event_time"), sep = " ") #divides column variables into two or more columns - tidyr package function

str_detect(names(sales5),"dt") #detect string in string vector
sales5[, date_cols] <- lapply(sales5[,date_cols], ymd) #using lapply to edit and replace cols


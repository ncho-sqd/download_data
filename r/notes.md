###R Learning Notes

## Data import
#CSV
sales<-read.csv('sales.csv', stringsAsFactors=F) #stringsAsFactors prevents char being read as factor var
#XLS/XLSX
read_excel("mbta.xlsx",skip=1) #readxl package

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
                   c("event_dt", "event_time"), sep = " ") #divides column variables into two or more columns(tidyr)
sales6 <- unite(sales5, venue_city_state, 
                venue_city, venue_state, sep = ", ") #concatenating two variables(tidyr)

str_detect(names(sales5),"dt") #detect string in string vector(stringr)
sales5[, date_cols] <- lapply(sales5[,date_cols], ymd) #using lapply to edit and replace cols

#Transposing data
mbta4<-gather(mbta3,month(key),thou_riders(value),-mode)  #Change wide to long
mbta5<-spread(mbta4,mode,thou_riders) #Change from long to wide

#Casting values
mbta4$thou_riders<-as.numeric(mbta4$thou_riders)

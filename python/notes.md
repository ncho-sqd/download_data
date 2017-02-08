###Python Learning Notes

"a"*5

type()

str()
int()
bool()

fam_ext = fam + ["a",1]
del(fam[2])
fam.index("mom") #which is equivalent to
fam.count("mom")
fam.append("me")


y=x #Set pointer to original list so will alter the original list.  Instead do below:
y=list(x)
y=x[:]

help()
round(number[,digits]) #specifying optional arguments

sister.capitalize()
sister.replace("a","az")

pip3 install numpy
import numpy as np #this is preferred for readability
from numpy import array  #no need to use np
np.array.shape #prints dimension of array
np_2d[0][2] is equivalent to np_2d[0,2]

#Intermediate
plt.plot(year,pop)

plt.show()
plt.clf()
plt.scatter(x,y,s=,c=,alpha=) #plots different size for each point by size s, color c, opacity is alpha
plt.text(x,y,'text')
plt.grid(True)

dictionary = {"key":"value"}
dictionary.keys()
"key" in dictionary
del(dictionary["key"])
df.index=id
pandas.read_csv('filepath',index_col=)  #read data into dataframe

df[["colname1","colname2"]]
df[1:2] #row selection
df.loc[["id1","id2"]]
df.loc[["id1","id2"],["colname1","colname2"]]

numpy.logical_and(bmi>21,bmi<22), logical_or(), logical_not() #these are logical operators for numpy arrays
if, else, elif #conditionals

#Subsetting dataframe
cars[np.logical_and(cars["cars_per_cap"]>=100, cars["cars_per_cap"]<=500)] #need to create subset boolean array by using panda series not df
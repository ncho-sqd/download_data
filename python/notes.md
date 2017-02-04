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
import numpy as np #this is prefereed for readability
from numpy import array  #no need to use np
np.array.shape #prints dimension of array
np_2d[0][2] is equivalent to np_2d[0,2]

#Intermediate
plt.plot(year,pop)

plt.show()


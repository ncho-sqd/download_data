### functions
# custom create max function
def max(a,b):
	if a>b:
		return a
	else:
		return b

# print function with formatting in c printf style
def greetings(name1,name2):
	print str.format("Hello {0}, this is {1}",name1, name2)

greetings("Neil", "Ashley")

### loops
i = 1
while i < 10:
	print i
	i += 1

def squares(n):
	i = 1
	while i <= n:
		print i**2
		i += 1

squares(20)

### lists
names = ['Ashley', 'Neil', 'Michael', 'Joe']
for nm in names:
	print nm, len(nm)
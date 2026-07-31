"""
In a file called einstein.py, implement a 
program in Python that prompts the user for 
mass as an integer (in kilograms) and then 
outputs the equivalent number of Joules as 
an integer. Assume that the user will input 
an integer.
"""

#Ask user for a value for m
m = int(input("m: "))

#Create the constant for c
c = 300000000

#Apply the Energy formula
#Save the result and print it
e = m * (c**2)
print(e)


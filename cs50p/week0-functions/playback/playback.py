"""
In a file called playback.py, 
implement a program in Python that 
prompts the user for input and then 
outputs that same input, replacing 
each space with ... (i.e., three periods).
"""

user_input = input()
user_input = user_input.replace(" ", "...")

print(user_input)

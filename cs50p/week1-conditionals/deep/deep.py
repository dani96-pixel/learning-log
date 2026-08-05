"""
In deep.py, implement a program that prompts the user for 
the answer to the Great Question of Life, the Universe and 
Everything, outputting Yes if the user inputs 42 or 
(case-insensitively) forty-two or forty two. Otherwise 
output No.
"""

# Ask for input
user_answer = input(
    "What is the Answer to the Great Question of Life, the "
    "Universe, and Everything? "
)

# Normalize the input
user_answer = user_answer.strip().lower()

# Look for matching answers and print the corresponding output.
match user_answer:
    case "42" | "forty-two" | "forty two":
        print("Yes")
    case _:
        print("No")

# bank.py
"""
In a file called bank.py, implement a program that prompts the 
user for a greeting. If the greeting starts with “hello”, 
output $0. If the greeting starts with an “h” (but not “hello”), 
output $20. Otherwise, output $100. 
Ignore any leading whitespace in the user’s greeting, and 
treat the user’s greeting case-insensitively.
"""

# Normalize the input so comparisons are case-insensitive.
greeting = input("Greeting: ").strip().lower()

# Compare Starting Greeting word with "hello"
if greeting.startswith("hello"):
    print("$0")
# Compare Starting Greeting word first letter with "h"
elif greeting.startswith("h"):
    print("$20")
# Greeting word not start with "h" so it is not "hello" also
else:
    print("$100")

# twttr.py
"""
In a file called twttr.py, implement a program that 
prompts the user for a str of text and then outputs 
that same text but with all vowels (A, E, I, O, and U) 
omitted, whether inputted in uppercase or lowercase.
"""

# Ask the user for a str
user_input = input("Input: ")


# Function to check vowels
def is_vowel(char: str) -> bool:
    """
    Determine if a char is a vowel or not
    """
    char = char.lower()
    if char in 'aeiou':
        return True
    else:
        return False


# Loop for to iterate the user input
result = ''
for char in user_input:
    if not is_vowel(char):
        result += char

# Show output
print(f"Output: {result}")

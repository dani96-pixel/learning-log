# camel.py

def main() -> None:
    """
    The main entry point of the script.

    It prompts the user to enter a string in CamelCase format, calls the 
    conversion function, and prints the final result in snake_case.

    Returns:
        None: The function performs side effects (printing) and does not return a value.
    """
    user_input = input("camelCase: ")
    converted_input = convert_to_snake_case(user_input)
    print(f"snake_case: {converted_input}")


def convert_to_snake_case(input: str) -> str:
    """
    Converts a string from CamelCase format to snake_case format.

    The function iterates through the input string. When an uppercase 
    letter is encountered, it prepends an underscore ('_') and converts 
    the letter to lowercase. All other characters are appended as is.

    Args:
        input: The string (str) in CamelCase format that needs conversion.

    Returns:
        str: The converted string in snake_case format.
    """
    converted = ""
    for character in input:
        if character.isupper():
            converted += "_"
            converted += character.lower()
        else:
            converted += character

    return converted


if __name__ == "__main__":
    main()

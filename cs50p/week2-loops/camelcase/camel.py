# camel.py
def main() -> None:
    user_input = input("camelCase: ")
    converted_input = convert_to_snake_case(user_input)
    print(f"snake_case: {converted_input}")


def convert_to_snake_case(input: str) -> str:
    """
    Receives an string, iterate it and convert the camelCase to snake_case
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

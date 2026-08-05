# extensions.py
"""
In a file called extensions.py, implement a program that 
prompts the user for the name of a file and then outputs 
that file's media type if the file's name ends, 
case-insensitively, in any of these suffixes:

.gif
.jpg
.jpeg
.png
.pdf
.txt
.zip

If the file's name ends with some other suffix or has no 
suffix at all, output application/octet-stream instead, 
which is a common default.
"""


def main() -> None:
    # Ask for file name and Normalize the input
    file_name = input("File name: ").strip().lower()

    result = check_extension(file_name)
    print(result)


def check_extension(s: str) -> str:
    """
    Return the MIME type for a file extension.
    """
    if s.endswith(".gif"):
        return "image/gif"
    elif s.endswith(".jpg") or s.endswith(".jpeg"):
        return "image/jpeg"
    elif s.endswith(".png"):
        return "image/png"
    elif s.endswith(".pdf"):
        return "application/pdf"
    elif s.endswith(".zip"):
        return "application/zip"
    elif s.endswith(".txt"):
        return "text/plain"
    else:
        return "application/octet-stream"


# Execute the program
if __name__ == "__main__":
    main()

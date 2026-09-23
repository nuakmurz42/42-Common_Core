import typing
import sys


def unpacked_file(file: typing.IO[str]) -> str:
    text = file.read()
    return text


if len(sys.argv) == 1:
    print(f"Usage: {sys.argv[0]} <file>")
else:
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        file = open(sys.argv[1], "r")
        try:
            text = unpacked_file(file)
            print("---")
            print()
            print(f"{text}")
            print()
            print("---")
        finally:
            file.close()
            print(f"File '{sys.argv[1]}' closed.")
    except Exception as error:
        print(f"Error opening file '{sys.argv[1]}': {error}")


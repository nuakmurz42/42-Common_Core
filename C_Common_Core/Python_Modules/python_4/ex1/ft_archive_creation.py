import typing
import sys


def unpacked_file(file: typing.IO[str]) -> str:
    text = file.read()
    return text


def write_file(text: str) -> None:
    new_text = text.split('\n')
    lines = ""
    for line in new_text:
        lines = lines + line + '#\n'
    
    print("Transform data:")
    print("---")
    print()
    print(f"{lines}")
    print()
    print("---")
    name = input("Enter new file name (or empty): ")
    if name:
        file = open(name, "w")
        try:
            file.write(lines)
            print(f"Saving data to '{name}'")
            print(f"Data saved in file '{name}'.")
        finally:
            file.close()
    else:
        print("Not saving data.")


if len(sys.argv) == 1:
    print(f"Usage: {sys.argv[0]} <file>")
else:
    print("=== Cyber Archives Recovery & Preservation ===")
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
            print()
        write_file(text)
            
    except Exception as error:
        print(f"Error opening file '{sys.argv[1]}': {error}")

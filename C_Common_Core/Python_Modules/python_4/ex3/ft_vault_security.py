print("=== Cyber Archives Security ===")

def secure_archive(file_name: str, action: str = "read", content: str = "") -> tuple[bool, str]:
    success = False
    try:
        if action == "read":
            with open(file_name, 'r') as file:
                text = file.read()
                success = True
                new_tuple = success, text
        elif action == "write":
            with open(file_name, 'w') as file:
                success_message = "Content successfully written to file"
                file.write(content)
                success = True
                new_tuple = success, success_message
    except Exception as error:
        new_tuple = success, str(error)
    return new_tuple

print("Using 'secure_archive' to read from a nonexistent file:")
message = secure_archive("123.txt")
print(message)
print()
print("Using 'secure_archive' to read from an inaccessible file:")
message = secure_archive("/etc/master.passwd")
print(message)
print()
print("Using 'secure_archive' to read from a regular file:")
message = secure_archive("ex3/123.txt")
print(message)
print()
print("Using 'secure_archive' to write previous content to a new file:")
message = secure_archive("ex3/new_file.txt", "write", message[1])
print(message)
print()
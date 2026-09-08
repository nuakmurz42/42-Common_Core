def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    print()
    try:
        nmb = input_temperature("25")
        print(f"Input data is '{nmb}'")
        print(f"Temperature is now {nmb}°C")
        print()
        bad_input = "abc"
        input_temperature(bad_input)
        print()
    except ValueError:
        print(f"Input data is '{bad_input}'")
        print("Caught input_temperature error: "
              f"invalid literal for int() with base 10: '{bad_input}'")
        print()
    print("All tests completed - program didn't crash!")

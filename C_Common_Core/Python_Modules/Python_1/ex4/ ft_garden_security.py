class Plant:
    def __init__(self, name: str, height: float, age_days: int):
        self.name = name.capitalize()
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            self.__height = 0.0
        else:
            self.__height = height
        if age_days < 0:
            print(f"{self.name}: Error, age can't be negative")
            self._age_days = 0
        else:
            self._age_days = age_days

    def get_height(self) -> float:
        return round(self.__height, 1)

    def set_height(self, height: float) -> None:
        if height < 0:
            print("Error, height can't be negative")
            print("Height update rejected")
            return
        self.__height = height
        print(f"Height updated: {self.get_height()}cm")

    def get_age(self) -> int:
        return self._age_days

    def set_age(self, age_days: int) -> None:
        if age_days < 0:
            print("Error, age can't be negative")
            print("Age update rejected")
            return
        self._age_days = age_days
        print(f"Age updated: {self.get_age()} days")

    def show(self) -> None:
        seed = self.name
        print(f"{seed}: {self.get_height()}cm, {self.get_age()} days old")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = Plant("rose", 25.0, 30)
    print("Plant created: ", end="")
    rose.show()
    print()
    rose.set_height(35.0)
    rose.set_age(32)
    print()
    rose.set_height(-35.0)
    rose.set_age(-32)
    print()
    print("Current state: ", end="")
    rose.show()

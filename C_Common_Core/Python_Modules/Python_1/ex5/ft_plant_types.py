class Plant:
    def __init__(self, name: str, height: float, age_days: int):
        self.name = name.capitalize()
        self.height = height
        self.age_days = age_days

    def grow(self) -> None:
        self.height += 2.1

    def age(self) -> None:
        self.age_days += 1

    def show(self) -> None:
        seed = self.name.capitalize()
        print(f"{seed}: {round(self.height, 1)}cm, {self.age_days} days old")


class Flower(Plant):
    def __init__(
            self,
            name: str,
            height: float,
            age_days: int,
            color: str
            ):
        super().__init__(name, height, age_days)
        self.color = color

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")

    def bloom(self) -> None:
        print(f" {self.name.capitalize()} is blooming beautifully")


class Tree(Plant):
    def __init__(
            self,
            name: str,
            height: float,
            age_days: int,
            trunk_diameter: float
            ):
        super().__init__(name, height, age_days)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of "
              f"{self.height}cm long and {self.trunk_diameter}cm wide.")


class Vegetable(Plant):
    def __init__(
            self,
            name: str,
            height: float,
            age_days: int,
            harvest_season: str
            ):
        super().__init__(name, height, age_days)
        self.harvest_season = harvest_season.capitalize()
        self.nutritional_value = 0

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")


print("=== Garden Plant Types ===")
print("=== Flower")
rose = Flower("rose", 15, 10, "red")
rose.show()
print(f" {rose.name} has not bloomed yet")
print("[asking the rose to bloom]")
rose.show()
rose.bloom()
print()
print("=== Tree")
oak = Tree("oak", 200.0, 365, 5.0)
oak.show()
print("[asking the oak to produce shade]")
oak.produce_shade()
print()
print("=== Vegetable")
tomato = Vegetable("tomato", 5.0, 10, "april")
tomato.show()
print("[make tomato grow and age for 20 days]")
for _ in range(1, 21):
    tomato.grow()
    tomato.age()
    tomato.nutritional_value += 1
tomato.show()

class Plant:
    shade: int

    class Statistics:
        def __init__(self) -> None:
            self._grow_calls = 0
            self._show_calls = 0
            self._age_calls = 0

        def display_stats(self) -> None:
            print(f"Stats: {self._grow_calls} grow, "
                  f"{self._age_calls} "
                  f"age, {self._show_calls} show")

    @classmethod
    def create_ano(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    def __init__(self, name: str, height: float, age_days: int):
        self.name = name.capitalize()
        self.height = height
        self.age_days = age_days
        self._stats = Plant.Statistics()
        self.type = "Plant"

    def grow(self) -> None:
        self._stats._grow_calls += 1

    def age(self) -> None:
        self._stats._age_calls += 1

    def show(self) -> None:
        seed = self.name.capitalize()
        self._stats._show_calls += 1
        print(f"{seed}: {round(self.height, 1)}cm, {self.age_days} days old")

    @staticmethod
    def check_age(age: int) -> bool:
        return age > 365


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
        self.type = "Flower"

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")

    def grow(self) -> None:
        super().grow()
        self.height += 8.0

    def bloom(self) -> None:
        print(f" {self.name.capitalize()} is blooming beautifully!")


class Seed(Flower):
    def __init__(
            self,
            name: str,
            height: float,
            age_days: int,
            color: str):
        super().__init__(name, height, age_days, color)
        self.seed = 0
        self.bloomed = False
        self.type = "Seed"

    def grow(self) -> None:
        super().grow()
        self.height += 22.0

    def age(self) -> None:
        super().age()
        self.age_days += 20

    def bloom(self) -> None:
        self.bloomed = True
        self.seed = 42

    def show(self) -> None:
        super().show()
        if self.bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")
        print(f" Seeds: {self.seed}")


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
        self.shade = 0
        self.type = "Tree"

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

    def produce_shade(self) -> None:
        self.shade += 1
        print(f"Tree {self.name} now produces a shade of "
              f"{self.height}cm long and {self.trunk_diameter}cm wide.")


def display_statistics(plant: Plant) -> None:
    plant._stats.display_stats()
    if plant.type == "Tree":
        print(f" {plant.shade} shade")


rose = Flower("rose", 15.0, 10, "red")
print("=== Garden statistics ===")
print("=== Check year-old")
print(f"Is 30 days more than a year? -> {rose.check_age(30)}")
print(f"Is 400 days more than a year? -> {rose.check_age(400)}")
print()
print("=== Flower")
rose.show()
print(f" {rose.name} has not bloomed yet")
print(f"[statistics for {rose.name}]")
display_statistics(rose)
print("[asking the rose to grow and bloom]")
rose.grow()
rose.show()
rose.bloom()
print(f"[statistics for {rose.name}]")
display_statistics(rose)
print()
print("=== Tree")
oak = Tree("oak", 200.0, 365, 5.0)
oak.show()
print(f"[statistics for {oak.name}]")
display_statistics(oak)
print("[asking the oak to produce shade]")
oak.produce_shade()
print("[statistics for Oak]")
display_statistics(oak)
print()
print("=== Seed")
sunflower = Seed("sunflower", 80.0, 45, "yellow")
sunflower.show()
print("[make sunflower grow, age and bloom]")
sunflower.grow()
sunflower.age()
sunflower.bloom()
sunflower.show()
print(f"[statistics for {sunflower.name}]")
display_statistics(sunflower)
print()
print("=== Anonymous")
ano = Plant.create_ano()
ano.show()
print(f"[statistics for {ano.name}]")
display_statistics(ano)

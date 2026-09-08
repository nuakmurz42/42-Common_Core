class Plant:
    def __init__(self, name: str, height: float, age_days: int):
        self.name = name
        self.height = height
        self.age_days = age_days

    def grow(self) -> None:
        self.height += 0.8

    def age(self) -> None:
        self.age_days += 1

    def show(self) -> None:
        seed = self.name.capitalize()
        print(f"{seed}: {round(self.height, 1)}cm, {self.age_days} days old")


if __name__ == "__main__":
    rose = Plant("rose", 25.0, 30)
    oak = Plant("oak", 200, 365)
    cactus = Plant("cactus", 5, 90)
    sunflower = Plant("sunflower", 80, 45)
    fern = Plant("fern", 15, 120)
    plants = [rose, oak, cactus, sunflower, fern]
    print("=== Plant Factory Output ===")
    for plant in plants:
        print("Created: ", end="")
        plant.show()

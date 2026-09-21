import random

print("=== Game Data Alchemist ===")
new_list = ['Alice', 'bob', 'Charlie', 'dylan', 'Emma', 'Gregory', 'john', 'kevin', 'Liam']
list_all_cap = [name.capitalize() for name in new_list]
list_only_cap = [name for name in new_list if name == name.capitalize()]
print(f"Initial list of players: {new_list}")
print(f"New list with all names capitalized: {list_all_cap}")
print(f"New list of capitalized names only: {list_only_cap}")
print()
new_dict = {name: random.randrange(1000) for name in list_all_cap}
print(f"Score dict: {new_dict}")
average = sum(new_dict.values()) / len(new_dict)
print(f"Score average is {round(average, 2)}")
high_scores = {name: score for name, score in new_dict.items() if score > average}
print(f"High scores: {high_scores}")
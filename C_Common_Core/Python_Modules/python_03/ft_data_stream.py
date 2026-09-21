import typing
import random


print("=== Game Data Stream Processor ===")
def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    players = ["bob", "alice", "dylon", "charlie"]
    actions = ["run", "move", "climb", "use", "grab",
               "swim", "release", "eat", "sleep"]
    while True:
        name = random.choice(players)
        action = random.choice(actions)
        event = name, action
        yield event

def consume_event(new_list: list[tuple[str, str]]) -> typing.Generator[tuple[str, str], None, None]:
    while new_list:
        index = random.randrange(len(new_list))
        removed_element = new_list.pop(index)
        yield removed_element

event = gen_event()
for number in range(0, 1000):
    player, action = next(event)
    print(f"Event {number}: Player {player} did action {action}")
new_list = []
list_gen = gen_event()
for _ in range(10):
    new_list.append(next(list_gen))
print(f"Built list of 10 events: {new_list}")
for arg in consume_event(new_list):
    print(f"Got event from list: {arg}")
    print(f"Remains in list: {new_list}")
import re
from collections import defaultdict

input = open("input.txt").read().split("\n")

collection = input

mem = defaultdict(list)

count = 0
for i, item in enumerate(collection):

	# print(item)
	bag_id = item.index("bag")

	bags = item[item.index("contain") + len("contain"):].split(",")
	# print(item[:bag_id - 1] + '#')
	# print(bags)

	for bag in bags:
		mem[item[:bag_id - 1]].append(bag[3:-4])
		# print(bag[3:-4])

	# ptr = re.findall(r'-?\d+', item)
	# nums = list(map(int, ptr))

count = 0

mem[" other"] = []

def recurse(color):
	if ("shiny gold" in mem[color]):
		return (1)

	items = mem[color]
	# print(items)
	for bag in items:
		if (recurse(bag) == 1):
			return (1)

	return (0)

for color in mem:
	print(color)

	count += recurse(color)

print(count)
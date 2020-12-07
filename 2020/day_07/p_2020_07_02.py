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
		mem[item[:bag_id - 1]].append((bag[3:-4], bag[1:3]))
		# print(bag[1:-4])

def recurse(color):

	total = 0
	for item in mem[color]:
		if (item[1] == 'no'):
			total += 0
		else:
			total += recurse(item[0]) * int(item[1]) + int(item[1])
		print(item, total + 1)

	return (total)


count = 0
count = recurse("shiny gold")

# print(mem)

print(count)
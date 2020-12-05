import re
from collections import defaultdict

input = open("input.txt").read().split("\n")

collection = input

# mem = defaultdict(list)

count = 0
for i, item in enumerate(collection):

	print(item)

	# ptr = re.findall(r'-?\d+', item)
	# nums = list(map(int, ptr))



print(count)
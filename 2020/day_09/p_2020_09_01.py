import re
from collections import defaultdict

input = open("input.txt").read().strip().split("\n")

collection = input

nums = list(map(int, input[:25]))
# print(nums, len(nums))

count = 0

for num in input[25:]:

	found = False

	for item in nums:
		if ((int(num) - item) in nums):
			found = True

	if (found == False):
		print(num)

	nums.pop(0)
	# print("Added", num)
	nums.append(int(num))

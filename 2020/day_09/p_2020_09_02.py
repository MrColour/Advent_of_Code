import re
from collections import defaultdict

input = open("input.txt").read().strip().split("\n")

nums = list(map(int, input))

for i, item in enumerate(nums):

	total = 0
	lis = []
	for j, item in enumerate(nums, start=i):
		total += nums[j]
		lis += [nums[j]]
		if (total == 258585477):
			print(min(lis) + max(lis))
			exit()
		if (total > 258585477):
			break


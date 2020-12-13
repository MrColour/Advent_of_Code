# (n + offset) % n

import re
from collections import defaultdict

input = open("input.txt").read().split("\n")

nums = input[1].split(",")

nums = [(int(n), i) for i, n in enumerate(nums) if ('x' not in n)]
# nums = [(29, 0), (41, 19), (601, 29), (23, 37), (13, 42), (17, 46), (19, 48), (463, 60), (37, 97)]

# print(nums)

delta = nums[0][0]
start = 0

check = 0
nums = nums[1:]

def find(start, delta, mod, offset):
	# print(mod, offset)
	while (1):
		if ((start + offset) % mod == 0):
			break
		start += delta

	return (start)

# while (check < len(nums)):
while (check < len(nums)):

	end = find(start + delta, delta, nums[check][0], nums[check][1])
	end2 = find(end + delta, delta, nums[check][0], nums[check][1])
	diff = end2 - end

	# print(end, end2, diff)
	start = end2
	delta = diff

	check += 1

print(end)
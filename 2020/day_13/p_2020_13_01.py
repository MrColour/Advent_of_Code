import re
from collections import defaultdict

input = open("input.txt").read().split("\n")

nums = input[1].split(",")

nums = [int(n) for n in nums if ('x' not in n)]

print(nums)

lo = 10000000000
n = 29
for i, item in enumerate(nums):
	div = 1002460 // item
	left = (div + 1) * item - 1002460
	if (left < lo):
		lo = left
		n = item

print(n * lo)

# (n + offset) % n

import re
from collections import defaultdict

input = open("input.txt").read().split("\n")

nums = input[1].split(",")

nums = [(int(n), i) for i, n in enumerate(nums) if ('x' not in n)]

print(nums)

delta = nums[0][0]

nums = nums[1:]

while (1):


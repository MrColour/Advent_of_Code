# (n + offset) % n

import re
from collections import defaultdict

input = open("input.txt").read().split("\n")

nums = input[1].split(",")

# nums = [(int(n), i) for i, n in enumerate(nums) if ('x' not in n)]
nums = [(29, 0), (41, 19), (601, 29), (23, 37), (13, 42), (17, 46), (19, 48), (463, 60), (37, 97)]

# nums = [(23, 37), (13, 42)]
# nums = [(29, 0), (41, 19), (601, 29)]
nums = [(29, 0), (41, 19), (601, 29), (23, 37), (13, 42), (17, 46),(19, 48), (463, 60), (37, 97)]

# print(nums)

# hi = 601

# for item in nums:
# 	if (item[0] == hi):
# 		off = item[1]

# 400838
# # 714589

start = 2068421404
# start = -off
# start = -37
while (1):

	found = True
	for item in nums:
		if not (((start + item[1]) % item[0]) == item[0] or ((start + item[1]) % item[0]) == 0):
			found = False
			break

	# if (start == 3417):
	# 	print("Here")
	# if not (start % 13 + 2 == 13):
	# 	found = False
	if (found == True):
		break
	# start += (23)
	start += (3632255887)

	# print(start)

print(start)
# 4199

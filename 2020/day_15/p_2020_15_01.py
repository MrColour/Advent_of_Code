from collections import defaultdict

input = open("input.txt").read().strip().split(',')

mem = defaultdict(list)
nums = list(map(int, input))

for i, t in enumerate(nums):
	mem[t] = [i + 1]

prev = nums[-1]
for i in range(len(nums) + 1, 2020 + 1):
	# print(mem[prev])
	if (len(mem[prev]) < 2):
		spoken = 0
	else:
		spoken = mem[prev][0] - mem[prev][1]
	mem[spoken].insert(0, i)

	prev = spoken

print(prev)

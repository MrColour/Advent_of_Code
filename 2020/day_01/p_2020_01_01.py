input = open("input.txt").read().splitlines()

nums = list(map(int, input))

for i, num in enumerate(nums):
	for j, other in enumerate(nums):
		if (j is not i and num + other == 2020):
			print(num, other)
			print(num * other)
			exit()


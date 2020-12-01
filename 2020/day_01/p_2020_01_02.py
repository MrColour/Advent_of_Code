input = open("input.txt").read().splitlines()

nums = list(map(int, input))

for i, num in enumerate(nums):
	for j, other in enumerate(nums):
		for k, other2 in enumerate(nums):
			if (j != i and j != k and num + other + other2 == 2020):
				print(num, other, other2)
				print(num * other * other2)
				exit()

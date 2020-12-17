import re
from collections import defaultdict

input = open("input.txt").read().split("\n")

collection = input

mem = defaultdict(lambda: '.')

for j, line in enumerate(input):
	for indx, c in enumerate(line):
		mem[(indx, j, 0, 0)] = c

print(mem)

def on_n(x, y, z, t):

	on = 0
	x -= 1
	y -= 1
	z -= 1
	t -= 1

	for i in range(3):
		for j in range(3):
			for k in range(3):
				for h in range(3):
				# print((x + k, y + j, z + i), mem[(x + k, y + j, z + i)])
				# seen += 1
					if (mem[(x + k, y + j, z + i, t + h)] == '#'):
						# print((x + i, y + j, z + k))
						on += 1

	if ((x + 1, y + 1, z + 1, t + 1) in mem and mem[(x + 1, y + 1, z + 1, t + 1)] == '#'):
		on -= 1

	# print(seen)
	return (on)

# for i, item in enumerate(collection):

	# print(item)

# print(on_n(1, 1, 0))

# print(on_n(1, 0, 0))


cycle = 6
for c in range(cycle):

	new = mem.copy()

	for i in range(-8, 16):
		for j in range(-8, 16):
			for k in range(-8, 16):
				for h in range(-8, 16):

					if (mem[(k, j, i, h)] == '#'):
						if (on_n(k, j, i, h) == 2 or on_n(k, j, i, h) == 3):
							# print((k, j, i, h), "turns on")
							new[(k, j, i, h)] = '#'
						else:
							new[(k, j, i, h)] = '.'
					elif (mem[(k, j, i, h)] == '.'):
						if (on_n(k, j, i, h) == 3):
							# print((k, j, i, h), "turns on")
							new[(k, j, i, h)] = '#'
						else:
							new[(k, j, i, h)] = '.'

	mem = new
	print(c)

# # print(mem)

count = 0
for item in mem:
	if (mem[item] == '#'):
		print(item)
		count += 1

print(count)
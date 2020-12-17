from collections import defaultdict

input = open("input.txt").read().split("\n")

collection = input
mem = defaultdict(lambda: '.')

for j, line in enumerate(input):
	for indx, c in enumerate(line):
		mem[(indx, j, 0)] = c

# print(mem)

def on_n(x, y, z):

	on = 0
	x -= 1
	y -= 1
	z -= 1
	for i in range(3):
		for j in range(3):
			for k in range(3):
				if (mem[(x + k, y + j, z + i)] == '#'):
					on += 1

	if (mem[(x + 1, y + 1, z + 1)] == '#'):
		on -= 1

	return (on)

cycle = 6
for c in range(cycle):

	new = mem.copy()

	for i in range(-20, 20):
		for j in range(-20, 20):
			for k in range(-20, 20):

				if (mem[(k, j, i)] == '#'):
					if (on_n(k, j, i) == 2 or on_n(k, j, i) == 3):
						# print((k, j, i), "turns on")
						new[(k, j, i)] = '#'
					else:
						new[(k, j, i)] = '.'
				elif (mem[(k, j, i)] == '.'):
					if (on_n(k, j, i) == 3):
						# print((k, j, i), "turns on")
						new[(k, j, i)] = '#'
					else:
						new[(k, j, i)] = '.'

	mem = new

count = 0
for item in mem:
	if (mem[item] == '#'):
		print(item)
		count += 1

print(count)
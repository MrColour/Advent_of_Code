from collections import defaultdict

input = open("input.txt").read().strip().split("\n")

collection = input

mem = defaultdict(int)

coords = {
		"e": (0, -1),
"ne": (-1, 0), "se": (1, -1),
"nw": (-1, 1), "sw": (1, 0),
		"w": (0, 1)
}

for line in input:

	at = 0
	axis_a = 0
	axis_b = 0
	while (at < len(line)):
		two = line[at:at + 2]
		d = two[0]
		if (two == 'se'):
			at += 1
			d = two
		if (two == 'sw'):
			at += 1
			d = two
		if (two == 'nw'):
			at += 1
			d = two
		if (two == 'ne'):
			at += 1
			d = two

		# print(d)

		a, b = coords[d]
		axis_a += a
		axis_b += b

		at += 1

	if (mem[(axis_a, axis_b)] == 0):
		mem[(axis_a, axis_b)] = 1
	else:
		mem[(axis_a, axis_b)] = 0

# print(mem)

count = 0
for item in mem:
	if (mem[item] == 1):
		count += 1

print(count)
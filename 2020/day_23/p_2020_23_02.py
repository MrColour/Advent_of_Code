from collections import defaultdict

circle = list(map(int, str(167248359)))

count = 0
at = 0
curr = 1

mem = {}

final = 10
while (final != 1000000 + 1):
	circle += [final]
	final += 1

for i, item in enumerate(circle):
	mem[item] = circle[(i + 1) % len(circle)]

print(len(circle))
move = 0
while (move < 10000000):

	a, b, c = mem[curr], mem[mem[curr]], mem[mem[mem[curr]]]
	# print(move, a, b, c)

	find = curr - 1
	while (1):
		if (find not in [a, b, c, 0]):
			break
		find -= 1
		if (find <= 0):
			find = 1000000

	mem[curr] = mem[c]

	last = mem[find]
	mem[find] = a
	mem[c] = last

	curr = mem[curr]

	move += 1

# print(mem[1], mem[mem[1]])
print(mem[1] * mem[mem[1]])


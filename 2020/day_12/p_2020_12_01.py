input = open("input.txt").read().split("\n")

collection = input

comp = {0: 'E', 1: 'S', 2: 'W', 3: 'N'}
comp_a = {'N': (0, 1), 'S': (0, -1), 'E': (1, 0), 'W': (-1, 0)}

d = 0

x = 0
y = 0
for i, item in enumerate(collection):

	# print(item)

	dd = 0
	if (item[0] == 'L'):
		dd = int(item[1:])
		dd //= 90
		dd *= -1
	if (item[0] == 'R'):
		dd = int(item[1:])
		dd //= 90

	d += dd
	d %= 4

	if (item[0] == 'N'):
		y += int(item[1:])
	if (item[0] == 'S'):
		y -= int(item[1:])
	if (item[0] == 'E'):
		x += int(item[1:])
	if (item[0] == 'W'):
		x -= int(item[1:])

	if (item[0] == 'F'):
		add = int(item[1:])
		x += comp_a[comp[d]][0] * add
		y += comp_a[comp[d]][1] * add

	# print(item, comp[d])
	# print(x, y)

# print(x, y)
print(abs(x) + abs(y))
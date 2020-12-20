import re
from collections import defaultdict

input = open("input.txt").read().split("\n\n")

collection = input

# mem = defaultdict(list)
mem = {}
ids = []

count = 0
for i, item in enumerate(collection):

	corner = []

	lines = item.split('\n')
	num = int(lines[0].split(' ')[1][:4])
	# print(num)

	top = list(lines[1])
	bottom = list(lines[len(lines) - 1])
	# print("Top   ", top)
	# print("Bottom", bottom)

	left = []
	right = []
	for line in lines[1:]:
		left += line[0]
		right += line[len(line) - 1]
	# print("Left  ", left)
	# print("Right ", right)

	ids += [num]
	mem[num] = [top, left, bottom, right]
	# print(item)

# print(ids)
# print(mem)
x = 0
y = 0

stop = len(ids) - 2

# print(num)
map_t = {}
map_t[(x, y)] = (mem[num], num)
ids.remove(num)

TOP = 0
LEF = 1
BOT = 2
RIG = 3

def check(tile, new):
	if (tile[TOP] == new[BOT]):
		# print("Top")
		return (True, (0, 1))
	if (tile[BOT] == new[TOP]):
		# print("Bot")
		return (True, (0, -1))
	if (tile[LEF] == new[RIG]):
		# print("Lef")
		return (True, (-1, 0))
	if (tile[RIG] == new[LEF]):
		# print("Rig")
		return (True, (1, 0))
	return (False, (0, 0))

def rot(mat):

	new = [['.' for char in row] for row in mat]

	print(new)

	# for y in range(len(mat)):
	# 	for x in range(len(mat[0])):


def fits(coords, n):
	x = coords[0]
	y = coords[1]

	tile, _ = map_t[coords][:]
	new = mem[n][:]
	flip = mem[n][:]
	flip = [flip[0][::-1], flip[3], flip[2][::-1], flip[1]]

	# print(mem[n][1])
	# print("Flip", flip[0][::-1])
	# print(mem[n])
	# print("Flip", flip)

	for i in range(4):
		# print("Checking")
		res = check(tile, new)
		res2 = check(tile, flip)
		# print(new)
		# print(flip)
		if (res[0]):
			# print("Res", n, res)
			return ((x + res[1][0], y + res[1][1]), new)
		if (res2[0]):
			# print("Res", n, res2)
			return ((x + res2[1][0], y + res2[1][1]), flip)
		new = [new[1][::-1], new[2], new[3][::-1], new[0]]
		flip = [flip[1][::-1], flip[2], flip[3][::-1], flip[0]]

	return ((0, 0), None)

i = 0
stop = len(input) - 1
# print(map_t)
# print(ids)
while (i < stop):

	for tile in map_t:
		for n in ids:
			coord, orient = fits(tile, n)
			# print(coord)

			if (coord != (0, 0)):
				break

		if (coord != (0, 0)):
			ids.remove(n)
			map_t[(coord)] = (orient, n)
			break

	i += 1

hi_x = 0
hi_y = 0

lo_x = 0
lo_y = 0

for item in map_t:
	if (item[0] >= hi_x and item[1] >= hi_y):
		hi_x = item[0]
		hi_y = item[1]

	if (item[0] <= lo_x and item[1] <= lo_y):
		lo_x = item[0]
		lo_y = item[1]

	# if (item[0] == -7):
	# 	print(item, map_t[item][1])
	# if (item[0] == 4):
	# 	print(item, map_t[item][1])

# print(hi_x, hi_y, lo_x)
delta = hi_x - lo_x

# print(map_t[(-7, 2)])
# print(map_t[(-7, -9)])
# print(map_t[(4, 2)])
# print(map_t[(4, -9)])

# print(1621 * 3547 * 3389 * 1657)
print(map_t[(hi_x, hi_y)][1] * map_t[(hi_x - delta, hi_y)][1] * map_t[(hi_x, hi_y - delta)][1] * map_t[(hi_x - delta, hi_y - delta)][1])
# print(count)
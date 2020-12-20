import re
from collections import defaultdict

input = open("input.txt").read().split("\n\n")

collection = input

mem = {}
ids = []

count = 0
for i, item in enumerate(collection):

	corner = []

	lines = item.split('\n')
	num = int(lines[0].split(' ')[1][:4])

	ids += [num]
	mem[num] = list(map(list, lines[1:]))

def get_edge(mat):
	top = mat[0]
	bottom = mat[len(mat) - 1]

	left = []
	right = []
	for line in mat[0:]:
		left += line[0]
		right += line[len(line) - 1]

	return ([top, left, bottom, right])

map_t = {}
map_t[(0, 0)] = (mem[num], num)
ids.remove(num)

TOP = 0
LEF = 1
BOT = 2
RIG = 3

def check(tile, new):
	if (tile[TOP] == new[BOT]):
		return (True, (0, 1))
	if (tile[BOT] == new[TOP]):
		return (True, (0, -1))
	if (tile[LEF] == new[RIG]):
		return (True, (-1, 0))
	if (tile[RIG] == new[LEF]):
		return (True, (1, 0))
	return (False, (0, 0))

def rot(mat):

	new = [['.' for char in row] for row in mat]

	for y in range(len(mat)):
		for x in range(len(mat[0])):
			new[x][len(mat[0]) - y - 1] = mat[y][x]
	return (new)

def flip(mat):
	new = []

	for y in range(len(mat)):
		new.append(mat[y][::-1])

	return (new)

def fits(coords, n):
	x = coords[0]
	y = coords[1]

	tile, _ = map_t[coords][:]
	new = mem[n][:]
	fl = flip(new)

	for i in range(4):
		res = check(get_edge(tile), get_edge(new))
		res2 = check(get_edge(tile), get_edge(fl))
		if (res[0]):
			return ((x + res[1][0], y + res[1][1]), new)
		if (res2[0]):
			return ((x + res2[1][0], y + res2[1][1]), fl)

		new = rot(new)
		fl = rot(fl)

	return ((0, 0), None)

i = 0

print("Making map", len(ids))
stop = len(ids)
while (i < stop):

	for tile in map_t:
		for n in ids:
			coord, orient = fits(tile, n)

			if (coord != (0, 0)):
				break

		if (coord != (0, 0)):
			ids.remove(n)
			map_t[(coord)] = (orient, n)
			break

	i += 1
	print(i)

print("Got map")

for coor in map_t:
	print(coor, map_t[coor][1])

glue = []
for r in range(2, -9 - 1, -1):
	new_r = [[] for i in range(len(map_t[(0, 0)][0]))]
	for c in range(-7, 4 + 1):
		for to, row in enumerate(map_t[(c, r)][0]):
			new_r[to] += row[1:-1]

	for row in new_r[1:-1]:
		glue.append("".join(row))

d = ["                  # ", "#    ##    ##    ###", " #  #  #  #  #  #   "]

has = {}
for row in range(len(d)):
	for col in range(len(d[0])):
		if (d[row][col] == '#'):
			has[(col, row)] = 1

print(has)

def search(sea):
	count = 0
	for row in range(len(sea) - 2):
		for col in range(len(sea[0]) - len(d[0])):
			found = True
			for loc in has:
				if (sea[row + loc[1]][col + loc[0]] != '#'):
					found = False
			if (found == True):
				count += 1

	return (count)

glue = rot(glue)
fl = flip(glue)

dragons = 0

for i in range(4):
	glue = rot(glue)
	fl = rot(fl)

	n = search(glue)
	n1 = search(fl)

	print(n)
	print(n1)

	if (n != 0):
		dragons = n
		break
	if (n1 != 0):
		dragons = n1
		break

	# print("new")
	# for row in fl:
	# 	print(''.join(row))

big = "\n".join("".join(row) for row in fl)
count = big.count("#") - (dragons * 15)
print(big)
print(count)
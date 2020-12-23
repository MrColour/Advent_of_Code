import re
from collections import defaultdict

circle = list(map(int, str(167248359)))

count = 0
at = 0
curr = 1

mem = defaultdict(int)

i = 0
while (i < 100):

	at = circle.index(curr)
	# print("move", i + 1)
	# print(circle)
	a = circle[(at + 1) % len(circle)]
	b = circle[(at + 2) % len(circle)]
	c = circle[(at + 3) % len(circle)]

	circle.remove(a)
	circle.remove(b)
	circle.remove(c)
	# print("pick up", a, b, c)

	find = curr - 1
	while (find not in circle):
		if (find < 0):
			find = max(circle)
			break
		find -= 1

	# print("des", find)
	place = circle.index(find) + 1
	# place %= len(circle)

	# old_find = place
	at = circle.index(curr)
	curr = circle[(at + 1) % len(circle)]
	circle[place:place] = [a, b, c]
	# print("curr", curr)

	# circle += a, b, c
	i += 1

# print(circle)


one = circle.index(1)
out = circle[one + 1:] + circle[:one]
out = [str(d) for d in out]

print("".join(out))

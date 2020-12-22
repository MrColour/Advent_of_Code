from collections import defaultdict

p1 =[39,15,13,23,12,49,36,44,8,21,28,37,40,42,6,47,2,38,18,31,20,10,16,43,5]
p2 = [29,26,19,35,34,4,41,11,3,50,33,22,48,7,17,32,27,45,46,9,25,30,1,24,14]

def recurse(arr1, arr2):
	mem1 = defaultdict(int)
	mem2 = defaultdict(int)

	p1c = arr1[:]
	p2c = arr2[:]
	while (len(p1c) != 0 and len(p2c) != 0):
		if (tuple(p1c) in mem1 or tuple(p2c) in mem2):
			return (1)
		else:
			mem1[(tuple(p1c))]
			mem2[(tuple(p2c))]

		# print(p1c)
		# print(p2c)
		pl1 = p1c.pop(0)
		pl2 = p2c.pop(0)

		# print(pl1, pl2)
		if (len(p1c) >= pl1 and len(p2c) >= pl2):
			if (recurse(p1c[:pl1], p2c[:pl2]) == 1):
				p1c += [pl1, pl2]
			else:
				p2c += [pl2, pl1]
		else:
			if (pl1 > pl2):
				p1c += [pl1, pl2]
			else:
				p2c += [pl2, pl1]

	if (p1c > p2c):
		return (1)
	else:
		return (2)

# print(len(p1), len(p2))
mem_1 = defaultdict(int)
mem_2 = defaultdict(int)
while (len(p1) != 0 and len(p2) != 0):

	if (tuple(p1) in mem_1 or tuple(p2) in mem_2):
		print("p1 wins")
	else:
		mem_1[(tuple(p1))]
		mem_2[(tuple(p2))]

	# print(p1)
	# print(p2)
	pl1 = p1.pop(0)
	pl2 = p2.pop(0)

	# print(pl1, pl2)
	if (len(p1) >= pl1 and len(p2) >= pl2):
		if (recurse(p1[:pl1], p2[:pl2]) == 1):
			p1 += [pl1, pl2]
		else:
			p2 += [pl2, pl1]
	else:
		if (pl1 > pl2):
			p1 += [pl1, pl2]
		else:
			p2 += [pl2, pl1]

if (len(p1) > len(p2)):
	big = p1
else:
	big = p2
big = big[::-1]
# print(big)

count = 0
for i, num in enumerate(big):
	count += num * (i + 1)

print(count)
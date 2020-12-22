p1 =[39,15,13,23,12,49,36,44,8,21,28,37,40,42,6,47,2,38,18,31,20,10,16,43,5]
p2 = [29,26,19,35,34,4,41,11,3,50,33,22,48,7,17,32,27,45,46,9,25,30,1,24,14]

while (len(p1) != 0 and len(p2) != 0):
	pl1 = p1.pop(0)
	pl2 = p2.pop(0)

	# print(p1)
	# print(p2)
	# print(pl1, pl2)
	if (pl1 > pl2):
		p1 += [pl1, pl2]
	else:
		p2 += [pl2, pl1]

# print(len(p1), len(p2))

if (len(p1) > len(p2)):
	big = p1
else:
	big = p2

# print(big)
big = big[::-1]

count = 0
for i, num in enumerate(big):
	count += num * (i + 1)

print(count)
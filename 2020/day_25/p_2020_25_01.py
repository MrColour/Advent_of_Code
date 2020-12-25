from collections import defaultdict

stopx = 12090988
stopy = 240583

loop = 0
val = 1
while (1):
	val *= 7
	val %= 20201227
	loop += 1
	if (val == stopy):
		break

print(loop)
fy = loop

loop = 0
val = 1
while (1):
	val *= 7
	val %= 20201227
	loop += 1
	if (val == stopx):
		break

fx = loop

loop = 0
val = 1
while (loop < fy):
	val *= stopx
	val %= 20201227
	loop += 1
print(val)

loop = 0
val = 1
while (loop < fx):
	val *= stopy
	val %= 20201227
	loop += 1
print(val)


print(loop)
from collections import defaultdict

input = open("inp.txt").read().split("mask = ")

collection = input

mem = defaultdict(int)

def recurse(mem, adr, num, branch):
	# print(branch)
	if not (any([1 if l == 'X' else 0 for l in branch])):
		# print('end', int(''.join(adr), 2))
		mem[int(''.join(adr), 2)] = num
		return

	indx = branch.index('X')

	branch[indx] = '0'
	# print(branch)

	adr[indx] = '0'
	# print(adr)
	# print(int(''.join(adr), 2))
	recurse(mem, adr, num, branch)

	adr[indx] = '1'
	# print(int(''.join(adr), 2))
	# print(adr)
	recurse(mem, adr, num, branch)
	branch[indx] = 'X'


for i, item in enumerate(collection):

	# print(item)

	banks = item.strip().replace("]", '').split("\n")

	mask_total = banks[0]

	# print(mask_total)

	or_o = ['1' if l == '1' else '0' for l in mask_total]
	and_o = ['1' if l == '0' else '1' for l in mask_total]

	branch = ['X' if l == 'X' else '0' for l in mask_total]
	# print(branch)
	# print(or_o)
	# print(and_o)

	banks = [line for line in banks[1:]]
	# banks = banks[1:]

	for i, add in enumerate(banks):
		# print(add)
		adr, num = add.replace(' ', '').split("=")

		adr = int(adr[4:])
		adr &= int(''.join(and_o), 2)
		adr |= int(''.join(or_o), 2)

		num = int(num)
		# print(bin(adr)[2:].zfill(36))
		adr = (bin(adr)[2:].zfill(36))
		# print(bin(adr)[2:])

		# print(adr)
		# print(num)
		recurse(mem, list(adr), num, branch)


# print(mem)
total = 0
for add in mem:
	print(add)
	total += mem[add]

print(total)
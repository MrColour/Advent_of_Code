from collections import defaultdict

input = open("input.txt").read().split("mask = ")

collection = input

mem = defaultdict(int)

for i, item in enumerate(collection):

	# print(item)

	banks = item.strip().replace("]", '').split("\n")

	mask_total = banks[0]

	or_o = ['1' if l == '1' else '0' for l in mask_total]
	and_o = ['0' if l == '0' else '1' for l in mask_total]
	# print(or_o)
	# print(and_o)

	banks = [line for line in banks[1:]]
	# banks = banks[1:]

	for i, add in enumerate(banks):
		# print(add)
		adr, num = add.replace(' ', '').split("=")

		adr = int(adr[4:])
		num = int(num)

		num &= int(''.join(and_o), 2)
		num |= int(''.join(or_o), 2)

		mem[adr] = num

		# print(adr)
		# print(num)

# print(mem)

total = 0
for add in mem:
	print(add)
	total += mem[add]

print(total)
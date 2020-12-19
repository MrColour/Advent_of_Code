from collections import defaultdict
from itertools import takewhile

input = open("input.txt").read().strip().split("\n")

collection = input

def op_query(string):
	ops = []
	nums = []

	string = string.replace(' ', '')
	# print(string)

	i = 0
	prec = 0
	prec_list = []
	while (i < len(string)):
		if (string[i].isdigit()):
			num = int(''.join(takewhile(str.isdigit, string[i:])))
			nums += [num]
			i += len(str(num)) - 1
		elif (string[i] == '('):
			prec += len(string)
		elif (string[i] == ')'):
			prec -= len(string)
		else:
			if (string[i] == '*'):
				prec_list += [prec]
			else:
				prec_list += [prec + 1]
			ops += [string[i]]
		i += 1

	return (nums, ops, prec_list)

count = 0
for item in collection:

	# print(item)
	nums, ops, prec = op_query(item)
	# print(nums)
	# print(ops)
	# print(prec)

	while (len(ops) > 0):
		do_i = prec.index(max(prec))

		op = ops[do_i]
		if (op == '*'):
			nums[do_i] = nums[do_i] * nums[do_i + 1]
		else:
			nums[do_i] = nums[do_i] + nums[do_i + 1]

		nums.pop(do_i + 1)
		prec.pop(do_i)
		ops.pop(do_i)

	# print(nums[0])
	count += nums[0]

print(count)
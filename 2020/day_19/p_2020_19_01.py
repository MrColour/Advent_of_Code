import re
from collections import defaultdict

input = open("input.txt").read().split("\n")
rules = open("rules.txt").read().split("\n")

collection = input

# mem = defaultdict(list)
s = []

for i, item in enumerate(rules):
	split = item.split(': ')
	# print(split)
	s += [(int(split[0]), split[1])]

# print(s)
rules_s = sorted(s, key=lambda x: x[0])
print(rules_s)

def condense(rules, num, dest):

	if (num == 4):
		return 'a'
	elif (num == 5):
		return 'b'
	else:
		choices = rules[num][1].split(' | ')

		out = []
		for choice in choices:
			# new = []
			nums = choice.split(' ')
			# ptr = re.findall(r'-?\d+', choice)
			# nums = list(map(int, ptr))

			print(nums, choice)
			for i, n in enumerate(nums):
				print("in", n)
				out += condense(rules, int(n), dest)
				print("Check", nums[i])

			out += '|'
		out[-1] = ''

		print(out)
		out = '(' + ''.join(out) + ')'
		return (''.join(out))
			# return ()
			# print(choice)
			# choices = rules[num].split('|')
		# print(choices)
	# return False

rule = []

print(condense(rules_s, 0, rule))

# count = 0
# for string in input:

# 	rule = []
# 	condense(rules[0], 0, rule)




# print(count)

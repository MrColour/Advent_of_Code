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
# print(rules_s)

# 0: 8 11

def condense(rules, num):

	start = 0
	stop = 0
	while (start < len(rules[num][1])):
		end = start

		# print("begin", rules[num][1][:start])
		while (end < len(rules[num][1]) and (rules[num][1][end].isdigit() or rules[num][1][start] == ')' or rules[num][1][start] == ' ' or rules[num][1][start] == 'a' or rules[num][1][start] == 'b' or rules[num][1][start] == '|' or rules[num][1][start] == '(')):
			end += 1

		# if (end > len(rules[num][1])):
		# 	continue

		no = int(rules[num][1][start:end])
		# print("catch", no)
		# print(rules[num][1][start:end])
		s = '(' + rules[no][1] + ')'
		# print(s)

		rules[num] = (num, rules[num][1][:start] + s + rules[num][1][end:])
		# print(rules)


		# print(start, rules[num][1])

		# print("Skop", rules[num][1][start:])
		# start = end
		while (start < len(rules[num][1]) and (rules[num][1][start] == ')' or rules[num][1][start] == ' ' or rules[num][1][start] == 'a' or rules[num][1][start] == 'b' or rules[num][1][start] == '|' or rules[num][1][start] == '(')):
			start += 1

		# print(rules[num][1])
		stop += 1

condense(rules_s, 0)
pat = '^' + rules_s[0][1].replace(' ', '') + '$'

# print(rules_s[0])
print(pat)

count = 0
for string in input:

	# print(pat)

	# pat = '(a)((aa|(bb)(ab|ba)|(ab|ba))(aa|bb))(b)'
	# pat = 'a((((aa|bb)(ab|ba))|((ab|ba)(aa|bb)))b'

	# print(pat)
	# print(string)

	g = re.match(pat, string)
	if (g != None):
		count += 1

	# print(string, g)

	# rule = []
	# condense(rules[0], 0, rule)

print(count)

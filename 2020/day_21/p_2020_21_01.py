from collections import defaultdict

input = open("input.txt").read().split("\n")

collection = input
all_name = defaultdict(list)
count = 0
all_i = []
for i, item in enumerate(collection):

	# print(item)
	ingr, conts = item.replace(')', '').split("(contains ")
	conts = conts.split(', ')
	ingr = ingr.strip()
	# print(conts)
	# print(ingr)
	all_i += ingr.split(' ')
	for allergen in conts:
		if (allergen not in all_name):
			# print(allergen, 'got added', ingr.split(' '))
			all_name[allergen] = [set(ingr.split(' '))]
		else:
			# print(allergen, 'got added', ingr.split(' '))
			all_name[allergen].append(set(ingr.split(' ')))

# print(all_name)
print(all_name['fish'])

ban = []
for allergen in all_name:
	left_over = set(all_name[allergen][0])
	# print("Set", left_over)

	for s in all_name[allergen]:
		# print("Cross", s)
		left_over = left_over.intersection(s)

	print(allergen, left_over)
	ban += left_over

print(ban)
# print(all_i)

count = 0
for i in all_i:
	if (i not in ban):
		count += 1
		# print("Good", i)

print(count)
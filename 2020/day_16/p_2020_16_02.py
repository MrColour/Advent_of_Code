from collections import defaultdict

input = open("tickets.txt").read().split("\n")

# Fields were gotten through vscode with shortcuts. Was faster ;)
fields = [[(35,796), (811,953)], [(25,224), (248,952)], [(47,867), (885,959)], [(44,121), (127,949)], [(49,154), (180,960)], [(35,532), (546,971)], [(41,700), (706,953)], [(25,562), (568,968)], [(31,672), (680,969)], [(43,836), (852,961)], [(38,291), (304,968)], [(31,746), (755,956)], [(46,711), (719,971)], [(35,584), (608,955)], [(39,618), (640,950)], [(25,308), (334,954)], [(26,901), (913,957)], [(33,130), (142,965)], [(34,395), (405,962)], [(46,358), (377,969)]]

valids = []
for line in input:

	valid = True
	nums = list(map(int, line.split(',')))
	# print(len(nums))

	for j, num in enumerate(nums):
		poss = False
		# print(num)
		for i, field in enumerate(fields):
			# print(field)
			# print(field[0][0] , num , field[0][1], field[1][0] , num , field[1][1])
			if ((field[0][0] <= num <= field[0][1]) or (field[1][0] <= num <= field[1][1])):
				# print(num)
				poss = True

		if (poss == False):
			valid = False

	if (valid == True):
		valids.append(nums)

# Assume all fields are valid for all rows, remove when proved that this row cannot be this field
checksum = [[at for at in range(20)] for c in range(20)]
# print(checksum)

for line in valids:

	nums = line
	# print(line)
	# print(len(nums))

	for j, num in enumerate(nums):
		poss = False
		# print(num)
		for i, field in enumerate(fields):
			# print(field)
			if ((field[0][0] <= num <= field[0][1]) or (field[1][0] <= num <= field[1][1])):
				# print(num)
				poss = True
			else:
				if (j in checksum[i]):
					# print(field[0][0] , num , field[0][1], field[1][0] , num , field[1][1])
					# print(num, j, "isnt field ", i)
					checksum[i].remove(j)

# this row in ticket is?
# {this_row: corresponding_field}
found = {}
while (len(found) < 19):
	for k, row in enumerate(checksum):

		for num in found:
			if (num in row):
				row.remove(num)

		if (len(row) == 1):
			# Meaning that row[0] must be the k + 1 field
			# this type of solution wouldn't work if one of them didn't always have length of one.
			# in which case one would need to brute force it, sudoku style.
			# print("lonely", row, k + 1)
			found[row[0]] = k + 1

# print(checksum)
# print(found)

# Faster to just copy the ticket and surround in brackets
ticket = [97,103,89,191,73,79,83,101,151,71,149,53,181,59,61,67,113,109,107,127]

total = 1
for j, row in enumerate(found):
	if (found[row] <= 6):
		total *= ticket[row]

print(total)

from collections import defaultdict

input = open("tickets.txt").read().split("\n")

# Fields were gotten through vscode with shortcuts. Was faster ;)
fields = [[(35,796), (811,953)], [(25,224), (248,952)], [(47,867), (885,959)], [(44,121), (127,949)], [(49,154), (180,960)], [(35,532), (546,971)], [(41,700), (706,953)], [(25,562), (568,968)], [(31,672), (680,969)], [(43,836), (852,961)], [(38,291), (304,968)], [(31,746), (755,956)], [(46,711), (719,971)], [(35,584), (608,955)], [(39,618), (640,950)], [(25,308), (334,954)], [(26,901), (913,957)], [(33,130), (142,965)], [(34,395), (405,962)], [(46,358), (377,969)]]

count = 0
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
				poss = True

		if (poss == False):
			valid = False
			count += num

print(count)

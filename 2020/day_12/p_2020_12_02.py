import math

input = open("input.txt").read().split("\n")

collection = input

waypoint = (10, 1)
ship = (0, 0)

d = 0

x = 0
y = 0
for i, item in enumerate(collection):

	angle = math.radians(int(item[1:]))
	if (item[0] == 'L'):
		nx = waypoint[0] * math.cos(angle) - waypoint[1] * math.sin(angle)
		ny = waypoint[0] * math.sin(angle) + waypoint[1] * math.cos(angle)
		waypoint = (round(nx), round(ny))
	if (item[0] == 'R'):
		nx = waypoint[0] * math.cos(-angle) - waypoint[1] * math.sin(-angle)
		ny = waypoint[0] * math.sin(-angle) + waypoint[1] * math.cos(-angle)
		waypoint = (round(nx), round(ny))

	amount = int(item[1:])

	if (item[0] == 'N'):
		wx = waypoint[0]
		wy = waypoint[1]
		waypoint = (wx, wy + amount)
	if (item[0] == 'S'):
		wx = waypoint[0]
		wy = waypoint[1]
		waypoint = (wx, wy - amount)
	if (item[0] == 'E'):
		wx = waypoint[0]
		wy = waypoint[1]
		waypoint = (wx + amount, wy)
	if (item[0] == 'W'):
		wx = waypoint[0]
		wy = waypoint[1]
		waypoint = (wx - amount, wy)

	if (item[0] == 'F'):
		shipx = ship[0] + waypoint[0] * amount
		shipy = ship[1] + waypoint[1] * amount
		ship = (shipx, shipy)

	# print(item)
	# print(ship, waypoint)


# print(ship[0], ship[1])
print(abs(ship[0]) + abs(ship[1]))
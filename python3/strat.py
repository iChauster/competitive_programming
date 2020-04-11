import collections
import math

def solve() :
	played = collections.defaultdict(list)
	players = int(input())
	combos = list()
	for player in range(players):
		combos.append(input())

	i = 0
	s = ""
	while len(combos) > 0:
		played.clear()
		for combo in combos:
			played[combo[i % len(combo)] ].append(combo)
		if len(played.keys()) == 3:
			return "IMPOSSIBLE"
		elif len(played.keys()) == 2:
			if "P" not in played:
				s += "R"
				combos = [x for x in combos if x not in played["S"]]
			elif "S" not in played:
				s += "P"
				combos = [x for x in combos if x not in played["R"]]
			elif "R" not in played:
				s += "S"
				combos = [x for x in combos if x not in played["P"]]
				
		else:
			y = list(played.keys())[0]
			if y == "R":
				s += "P"
				combos = [x for x in combos if x not in played["R"]]
			elif y == "S":
				s += "R"
				combos = [x for x in combos if x not in played["S"]]
			else:
				s += "S"
				combos = [x for x in combos if x not in played["P"]]

		i += 1

	return s

for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
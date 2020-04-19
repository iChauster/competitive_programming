import collections
import math

m = {"S": (0,1), "N": (0,-1), "W": (-1,0), "E" : (1, 0)}
ans = [1,1]


def substring(s):
	multiplier = 1
	dx = 0
	dy = 0
	stackChange = list()
	multi = list()
	for c in s:
		if c.isdigit():
			multi.append(int(c))
			while (len(stackChange) > 0):
				curr = stackChange.pop()
				dx += curr[0] * multiplier
				dy += curr[1] * multiplier
			multiplier *= int(c)
		elif c == ')':
			currMultiplier = multi.pop()
			while (len(stackChange) > 0):
				curr = stackChange.pop()
				dx += curr[0] * multiplier
				dy += curr[1] * multiplier
			multiplier /= currMultiplier
		elif c.isalpha():
			stackChange.append(m[c])

	while (len(stackChange) > 0):
			curr = stackChange.pop()
			dx += curr[0] * multiplier
			dy += curr[1] * multiplier
	return (dx, dy)


def solve() :
	s = input()
	
	a = substring(s)
	return ("%d %d" % (a[0] % 1e9 + 1, a[1] % 1e9 + 1))


for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
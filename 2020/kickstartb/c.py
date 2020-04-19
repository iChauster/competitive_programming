import collections
import math

m = {"S": (0,1), "N": (0,-1), "W": (-1,0), "E" : (1, 0)}

def substring(s):
	dx = 0
	dy = 0
	stackChange = list()
	multi = [1]
	for c in s:
		if c.isdigit():			
			while (len(stackChange) > 0):
				curr = stackChange.pop()
				dx = (dx + curr[0] * multi[-1]) % 1e9
				dy = (dy + curr[1] * multi[-1]) % 1e9
			multi.append(int(c) * multi[-1] % 1e9)
		elif c == ')':
			while (len(stackChange) > 0):
				curr = stackChange.pop()
				dx = (dx + curr[0] * multi[-1]) % 1e9
				dy = (dy + curr[1] * multi[-1]) % 1e9
			multi.pop()
		elif c.isalpha():
			stackChange.append(m[c])

	while (len(stackChange) > 0):
			curr = stackChange.pop()
			dx = (dx + curr[0] * multi[-1]) % 1e9
			dy = (dy + curr[1] * multi[-1]) % 1e9
	return (dx, dy)


def solve() :
	s = input()
	
	a = substring(s)
	return ("%d %d" % (a[0] % 1e9 + 1, a[1] % 1e9 + 1))


for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
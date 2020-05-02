import collections
import math

mp = {"N": 1, "S": -1, "W": -1, "E": 1}
def solve() :
	x,y, m = input().split()
	x = int(x)
	y = int(y)
	for index in range(len(m)):
		c = m[index]
		if c == "N" or c == "S":
			y += mp[m[index]]
		else:
			x += mp[m[index]]
		if index + 1 >= abs(x) + abs(y):
			return index + 1
	return "IMPOSSIBLE"





for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
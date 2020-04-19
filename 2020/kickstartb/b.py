import collections
import math

def solve() :
	routes, maxDay = [int(x) for x in input().split()]
	n = [int(x) for x in input().split()]
	ans = 0
	for i in range(len(n) - 1, -1, -1):
		x = n[i]
		m = maxDay % x
		if m > 0 :
			maxDay = maxDay - m

	return maxDay

for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
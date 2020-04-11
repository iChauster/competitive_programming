import collections
import math
import operator as op
from functools import reduce

comb = [[0] * 500 for i in range(500)]
prefix = [[0] * 500 for i in range(500)]

def ncr(n, r):
	if comb[n][r] == 0:
	    r = min(r, n-r)
	    numer = reduce(op.mul, range(n, n-r, -1), 1)
	    denom = reduce(op.mul, range(1, r+1), 1)
	    comb[n][r] = numer / denom
	    return numer / denom
	else:
		return comb[n][r]

def solve() :
	s = 0
	row = 0
	queries = 0
	target = int(input())
	log = list()
	go = True
	while (go):
		# compute row sum up to n/2
		s += ncr(row, math.floor(row / 2))
		log.append((row, math.floor(row/2)))
		projectedSum = s
		addQs = 0
		for x in range(math.floor(row/2)):
			projectedSum += ncr(row, x)
			addQs += 1
		if target - projectedSum < 500 - (queries + addQs):
			for i in range(math.floor(row/2) - 1, -1, -1):
				log.append((row, i))
			s = projectedSum
			go = False
		else:
			queries += 1
			row += 1
	# left off on row
	nextRow = row + 1
	print(target - s)
	for x in range(int(target - s)):
		log.append((nextRow, 0))
		nextRow += 1

	for x in log:
		print("%d %d" % (x[0] + 1, x[1] + 1))


for case in range(int(input())):
	print('Case #%d:' % (case + 1))
	solve()
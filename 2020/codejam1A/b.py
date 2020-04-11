import collections
import math
import operator as op
from functools import reduce

dp = [[0] * 500 for i in range(500)]
class Node:
	def __init__(self, index, l, parent, value):
		self.edges = l
		self.index = index
		self.parent = parent
		self.value = value


def ncr(n, r):
	if dp[n][r] == 0:
	    r = min(r, n-r)
	    numer = reduce(op.mul, range(n, n-r, -1), 1)
	    denom = reduce(op.mul, range(1, r+1), 1)
	    dp[n][r] = numer / denom
	    return numer / denom
	else:
		return dp[n][r]
def getValue(r, k):
	return ncr(r, k)

def generateTree(maxVal):
	q = [Node((0,0), [], None, 1)]

	first = q[0]

	while len(q) > 0:
		gen = q.pop(0)
		if (gen.value == maxVal):
			return gen

		x = gen.index[0] # row
		y = gen.index[1] # column

		# north
		if x - 1 >= 0 and y - 1 >= 0 and y - 1 < x - 1:
			if gen.index != (x-1,y-1):
				n = Node((x-1,y-1), [], gen, ncr(x-1,y-1) + gen.value)
				gen.edges.append(n)
				q.append(n)
		if x - 1 >= 0 and y < x - 1:
			if gen.index != (x - 1, y):
				n = Node((x-1,y), [], gen,ncr(x-1,y) + gen.value)
				gen.edges.append(n)
				q.append(n)
		# can always go down
		if gen.index != (x+1, y):
			n = Node((x+1,y), [], gen, ncr(x+1,y) + gen.value)
			gen.edges.append(n)
			q.append(n)
		if gen.index != (x+1, y+1):
			n = Node((x+1,y+1), [], gen, ncr(x+1,y+1) + gen.value)
			gen.edges.append(n)
			q.append(n)
		
		#left right
		if y + 1 < x :
			if gen.index != (x, y+1):
				n = Node((x,y+1), [], gen, ncr(x,y+1) + gen.value)
				gen.edges.append(n)
				q.append(n)
		if y - 1 >= 0 :
			if gen.index != (x, y-1):
				n = Node((x,y-1), [], gen, ncr(x,y-1) + gen.value)
				gen.edges.append(n)
				q.append(n)

def solve() :
	value = int(input())
	first = generateTree(value)
	l = [first]
	while (first.parent):
		l.append(first.parent)
		first = first.parent
	l.reverse()
	for n in l:
		print("%d %d" % (n.index[0] + 1, n.index[1] + 1))

for case in range(int(input())):
	print('Case #%d:' % (case + 1))
	solve()
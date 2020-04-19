import collections
import math

def solve() :
	W, H, L, U, R, D = [int(x) for x in input().split()]
	possibleWays = 2 ** max(W, H) - 1
	dp = collections.defaultdict(int)

	for l in range(L, R + 1):
		for u in range(U, D + 1):
			dp[(l,u)] = 0

	def getWays():
		for i in range(0, L):
			dp[(0,i)] = 1 if dp[(0,i)]  != -1 else -1
		for j in range(0, U):
			dp[(j,0)] = 1 if dp[(j,0)]  != -1 else -1

		for i in range(1,W):
			for j in range(1,H):
				if dp[(i,j)] == 0:					
						top = dp[(i-1,j)]
						left = dp[(i, j -1)]
						if top == -1:
							top = 0
						if left == -1:
							left = 0
						dp[(i,j)] = left + top
	getWays()
	return dp[(W-1, H-1)] / possibleWays

for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
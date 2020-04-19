import collections
import math

def solve() :
	r, s = [int(x) for x in input().split()]
	sl = []
	for i in range(1,r+1):
		for j in range(1,s + 1):
			sl.append((j,i))
	ans = []
	def clear(sublist):
		rank = sublist[-1][0]
		ops = rank - 1
		while (ops > 0) :
			i = 0
			while(1):
				if (sublist[i][0] == rank):
					break
				i += 1
			j = len(sublist) - 1
			ans.append((i + 1,j - i - 1))
			print(i,j)
			print(sublist)
			sublist = sublist[i + 1: j] + sublist[:i]
			print(sublist)
			ops -= 1
		return sublist
	sb = clear(sl)
	print(sb)
	print(ans)





for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
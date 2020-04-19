import collections
import math

def solve() :
	x, y = [int(a) for a in input().split()]
	ans = list()
	master = collections.defaultdict(list)
	stack = [(x,y,"")]
	newstack = []
	def simulate(a, b, currentVal, currentString):
			if (a % 2 == 1 and b % 2 == 1):
				return
			if a == 0 and b == 0:
				return currentString
			if (a - currentVal) % 2 == 0:
				newstack.append((a-currentVal, b, currentString + "E"))
			if (a + currentVal) % 2 == 0:
				newstack.append((a+currentVal, b, currentString + "W"))
				
			if (b - currentVal) % 2 == 0:
				newstack.append((a, b-currentVal, currentString + "N"))
				
			if (b + currentVal) % 2 == 0:
				newstack.append((a, b + currentVal, currentString + "S"))
	
	currentVal = 1
	while (len(stack) > 0 or len(newstack) > 0):
		x,y,z = stack.pop(0)
		
		ret = simulate(x,y, currentVal, z)
		if ret:
			return ret
		if len(stack) == 0:
			stack = newstack.copy()
			newstack.clear()
			currentVal *= 2 
	return "IMPOSSIBLE"


for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
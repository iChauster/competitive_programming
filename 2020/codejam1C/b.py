import collections
import math

def first(master):
	for key, val in sorted(master.items(), key = lambda x: x[1], reverse = True):
		if len(key) == 2:
			return key[1]

def getAnswer(limit, master, first):
	ans = ["0"] * 10
	ans[0] = first
	solvedIndex = 1
	for key, val in sorted(master.items(), key = lambda x: x[1], reverse = True):
		if solvedIndex > 9:
			break
		if len(key) == limit:
			firstLetterKey = key[0]
			if firstLetterKey not in ans:
				ans[solvedIndex] = firstLetterKey
				solvedIndex += 1
	return ans

def solve() :
	ub = int(input())
	master = collections.defaultdict(int)
	maxKeyLength = 0
	for i in range(10000):
		q, r = input().split()
		master[r] += 1
		maxKeyLength = max(maxKeyLength, len(r))


	ans = ["0"] * 10
	f = first(master)
	for i in range(1, maxKeyLength + 1):
		yer = getAnswer(i, master, f)
		if "0" not in yer:
			print("setting answer")
			ans = yer

	return "".join(ans)

'''
import collections
import math

def solve() :
	ub = int(input())
	master = collections.defaultdict(list)

	for i in range(10000):
		q, r = input().split()
		q = int(q)
		master[q].append(r)
	
	ans = [-1] * 10
	start = master[10]
	for y in start:
		if len(y) == 2:
			ans[1] = y[0]
			ans[0] = y[1]

	for i in range(10, 99):
		z = master[i]
		strep = str(i)
		if len(z) > 0:
			firstDigit = int(strep[0])
			secondDigit = int(strep[1])
			for pair in z:
				if len(pair) == 2:
					firstn = pair[0]
					secondn = pair[1]
					if firstn == ans[firstDigit]:
						if secondn not in ans:
							ans[secondDigit] = secondn
	return "".join(ans)
			
'''
		
for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
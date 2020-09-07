import heapq

def findError(n, length) :
	evenHeap = []
	oddHeap = []
	for x in range(len(n)) :
		if x % 2 == 0:
			evenHeap.append(n[x])
		elif x % 2 == 1:
			oddHeap.append(n[x])


	return reassemble(sorted(evenHeap), sorted(oddHeap), n)

def reassemble(evenHeap, oddHeap, fullList):
	for currentIndex in range(len(fullList)-1):
		if currentIndex % 2 :
			if oddHeap[(currentIndex - 1) // 2] > evenHeap[(currentIndex + 1) // 2]:
				return currentIndex
		else:
			if evenHeap[currentIndex // 2] > oddHeap[currentIndex // 2]:
				return currentIndex

	return "OK"



for case in range(int(input())):
	n = int(input())
	setN = [int(j) for j in input().split(' ')]
	length = len(setN)
	result = findError(setN, length)
	print('Case #%d: %s' % (case+1, result))





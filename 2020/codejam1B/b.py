import collections
import math

def searchRight(left, right, y):
	global centerHit
	lastHit = left
	while left < right:
		mid = (left + right) // 2
		print("%d %d" % (mid, y))
		currentFile.write("sr: %d %d\n" % (mid, y))
		resp = input()
		currentFile.write("%s\n" % resp)
		if resp == "HIT":
			lastHit = mid
			left = mid + 1
		elif resp == "CENTER":
			centerHit = True
			return
		else:
			right = mid - 1
	return lastHit

def searchLeft(left, right, y):
	global centerHit
	lastHit = right
	while left < right:
		currentFile.write("%d %d \n" % (left, right))
		mid = (left + right) // 2
		print("%d %d" % (mid, y))
		currentFile.write("sl: %d %d\n" % (mid, y))
		resp = input()
		currentFile.write("%s\n" % resp)
		if resp == "HIT":
			lastHit = mid
			right = mid - 1
		elif resp == "CENTER":
			centerHit = True
			return
		else:
			left = mid + 1
	return lastHit

def searchUp(down, up, x):
	global centerHit
	lastHit = down
	while down < up:
		mid = (down + up) // 2
		print("%d %d" % (x, mid))
		resp = input()
		if resp == "HIT":
			lastHit = mid
			down = mid + 1
		elif resp == "CENTER":
			centerHit = True
			return
		else:
			up = mid - 1
	return lastHit

def searchDown(down, up, x):
	global centerHit
	lastHit = up
	while down < up:
		mid = (down + up) // 2
		print("%d %d" % (x, mid))
		resp = input()
		if resp == "HIT":
			lastHit = mid
			up = mid - 1
		elif resp == "CENTER":
			centerHit = True
			return
		else:
			down = mid + 1
	return lastHit

def solve() :
	guar = [(-5e8, 5e8), (0, 7e8), (5e8, 5e8), (-7e8, 0), (0,0), (7e8, 0), (-5e8, -5e8), (0, -7e8), (5e8, -5e8)]

	# throw
	searchCoord = None
	for x,y in guar:
		print("%d %d" % (x,y))
		currentFile.write("%d %d\n" % (x,y))
		resp = input()
		currentFile.write("%s\n" % resp)
		if resp == "HIT":
			searchCoord = (x,y)
			break
		elif resp == "CENTER":
			currentFile.write("THE CENTER\n")
			return
		else:
			continue
	if searchCoord == None:
		print("%d %d" % (3e9, 3e9))
	# far Right
	# currentFile.write("Searching %d %d\n" % searchCoord)
	FR = searchRight(searchCoord[0], 1e9, searchCoord[1])
	if centerHit: return
	FL = searchLeft(-1e9, searchCoord[0], searchCoord[1])
	if centerHit: return
	FU = searchUp(searchCoord[1], 1e9, searchCoord[0])
	if centerHit: return
	FD = searchDown(-1e9, searchCoord[1], searchCoord[0])
	if centerHit: return
	# expectedCenter
	leftSum = (FL + FR) / 2
	rightSum = (FU + FD) / 2

	combos = set([(math.ceil(leftSum), math.ceil(rightSum)), (math.ceil(leftSum), math.floor(rightSum)), 
	(math.floor(leftSum),math.ceil(rightSum)), (math.floor(leftSum), math.floor(rightSum))])
	currentFile.write("%s\n" % combos)
	for xt, yt in combos:
		print("%d %d" % (xt, yt))
		currentFile.write("%d %d" % (xt, yt))
		resp = input()
		currentFile.write("%s\n" % resp)
		if resp == "CENTER":
			return

inp = input().split()
currentFile = open("log.log", "w")
CASES, MAX, MIN = [int(x) for x in inp]
currentFile.write("%d %d %d\n" % (CASES, MAX, MIN))
centerHit = False
for case in range(CASES):
	currentFile.write("Case %d\n" % (case))
	centerHit = False
	solve()

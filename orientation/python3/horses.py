def findHorses() :
	maxTime = -1
	for horse in range(n) :
		position, speed = map(int, input().split())
		maxTime = max(maxTime, (d - position)/speed)

	return d/maxTime

for case in range(int(input())):
	d, n = map(int, input().split())
	print('Case #%d: %s' % (case+1, solve()))
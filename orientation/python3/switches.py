
def calculateHacks(stri) :
	set =  [0]
	currentIndex = 0
	currentCount = 0
	for s in stri :
		if s == 'C':
			currentIndex += 1
			set.append(0)
		elif s == 'S':
			set[currentIndex] += 1
			currentCount += (2 ** currentIndex)
	difference = currentCount - d
	return str(findSwitches(set, difference))

def findSwitches(set, difference):
	if difference > 0:
		change = False
		for index, count in reversed(list(enumerate(set))):
			greatestChange = 2 ** (index-1)
			if count > 0 and index > 0:
				change = True
				difference -= greatestChange
				set[index] = count - 1
				set[index - 1] = set[index - 1] + 1
				break;
		if change: 
			v = findSwitches(set,difference)
			if(isinstance(v,int)):
				return v + 1
			else: return "IMPOSSIBLE"
		else: return "IMPOSSIBLE"
	else:
		return 0

for case in range(int(input())):
	line = input().split()
	d = int(line[0])
	p = str(line[1])
	print('Case #%d: %s' % (case+1, calculateHacks(p)))
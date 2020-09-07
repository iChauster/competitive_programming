import collections

def indexWord(word):
	if len(word) > 0:
		master[word] += 1
		indexWord(word[1:])

def descend(word):
	if (len(word) > 0):
		master[word] -= 2
		descend(word[1:])

def solve() :
	master.clear()
	words = int(input())
	offset = 0
	for word in range(words):
		indexWord(input())

	# traverse tree
	count = 0
	keys = list(master.keys())
	keys.sort(key=lambda x: len(x), reverse = True)
	for key in keys:
		value = master[key]
		if value >= 2:
			count += 2
			descend(key)
	return count

for case in range(int(input())):
	master = collections.defaultdict(int)
	print('Case #%d: %s' % (case+1, solve()))
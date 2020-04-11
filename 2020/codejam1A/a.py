import collections
import math
prefix = ""
suffix = ""

def processPrefix(s):
	global prefix
	if len(s) > 0:
		if s not in prefix:
			if prefix in s:
				prefix = s
				return 0
			else:
				return -1
		else:
			if prefix[:len(s)] != s:
				return -1

	return 0

def processSuffix(s):
	global suffix
	if len(s) > 0:
		if s not in suffix:
			if suffix in s:
				suffix = s
				return 0
			else:
				return -1
		else:
			# check the ends
			if suffix[-len(s):] != s:
				return -1

	return 0


def solve() :
	words = int(input())
	global prefix
	global suffix
	prefix = ""
	suffix = ""
	middle = ""
	fail = False
	for word in range(words):
		s = input().strip().split("*")
		p = processPrefix(s[0])
		suf = processSuffix(s[-1])

		if len(s) > 2:
			for x in range(1, len(s) - 1):
				middle += s[x]
		if p == -1 or suf == -1:
			fail = True

	if fail:
		return "*"


	return prefix + middle + suffix


for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
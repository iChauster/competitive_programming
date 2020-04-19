import collections
import math

def solve() :
	numbers = int(input())
	n = input().split()
	nums = [int(x) for x in n]
	count = 0
	for i in range(1, len(nums) - 1):
		x = nums[i]
		if x > nums[i - 1] and x > nums[i + 1]:
			count += 1
	return count

for case in range(int(input())):
	print('Case #%d: %s' % (case + 1, solve()))
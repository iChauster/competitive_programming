import collections

def getBeauty(stacks, plates):
    check = tuple([len(x) for x in stacks])
    if check in master:
        return 0

    beauty = 0
    
    if plates == 0:
        return 0

    for stackIndex in range(len(stacks)):
        stack = stacks[stackIndex]
        if len(stack) > 0:
            value = int(stack.pop(0))
            chooseValue = 0
            key = tuple([len(x) for x in stacks])
            beauty = max(getBeauty(stacks, plates - 1) + value, beauty)
            if key not in master:
                master[key] = beauty
            stack.insert(0, value)


    return beauty

master = collections.defaultdict(int)
for case in range(int(input())):
    numStacks, perStack, numPlates = input().split()
    stacks = list()
    for it in range(int(numStacks)):
        stacks.append(input().split())
    print('Case #%d: %s' % (case+1, getBeauty(stacks, int(numPlates))))
    master.clear()
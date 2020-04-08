import itertools
import collections

def solver(combinations, numWords):
    master = collections.defaultdict(int)
    orderedSets = collections.defaultdict(int)
    for combo in combinations:
        orderedSets[comboo] = calculatePrefixScore(combo)

    a = list(sorted(orderedSets, key = orderedSets.__getitem__, reverse = True))

    count = 0
    while count < numWords:
        a.pop()
        




def calculatePrefixScore(words):
    i = 0
    matching = True
    while matching:
        charToMatch = words[0][i]
        for wid in range(1, len(words)):
            word = words[wid]
            if word[i] != charToMatch:
                matching = False
                break
        if matching:
            i += 1
    return i
    


for case in range(int(input())):
    words, groupsize = input().split()
    wordlist = list()

    for w in range(int(words)):
        wordlist.append(str(input()))

    combos = list(itertools.combinations(wordlist, int(groupsize)))
    print(list(combos))

    print('Case #%d: %s' % (case+1, solver(combos, len(wordlist))))
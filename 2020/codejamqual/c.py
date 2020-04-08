import collections
def solve() -> str:
    a = int(input())
    l = list()
    master = collections.defaultdict(str)
    original = list()
    for x in range(a):
        first, second = [int(x) for x in input().split()]
        l.append((first, second))

    original = l.copy()
    l.sort(key = lambda tup:tup[0])
    
    endpointC = 0
    endpointJ = 0

    
    for event in l:
        start, end = event
        if event in master:
            if master[event] == "D":
                return "IMPOSSIBLE"
            else:
                master[event] = "D"
        else:
            if start >= endpointC:
                endpointC = end
                master[event] = "C"
            elif start >= endpointJ:
                endpointJ = end
                master[event] = "J"
            else :
                return "IMPOSSIBLE"

    ret = ""

    for key in original:
        value = master[key]

        if value == "D":
            ret += "C"
            master[key] = "J"
        else:
            ret += master[key]

    return ret


for case in range(int(input())):
    print('Case #%d: %s' % (case+1, solve()))
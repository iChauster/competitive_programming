import collections

def solve():
    n = int(input())
    
    colList = [set() for x in range(n)]

    trace = 0
    rowProb = 0
    colProb = 0
    for x in range(n):
        row = input().split()
        rowSet = set()
        for y in range(len(row)):
            s = colList[y]            
            value = int(row[y])
            
            if x == y:
                trace += value
            
            rowSet.add(value)
            s.add(value)

        rowProb = rowProb + 1 if(len(rowSet) < n) else rowProb

    for s in colList:
        colProb = colProb + 1 if (len(s) < n) else colProb
            

    return trace, rowProb, colProb



for case in range(int(input())):
    t, r, c = solve()
    print('Case #%d: %d %d %d' % (case+1, t, r, c))
import heapq

def findError(v, length) :
    v_ieven = []
    v_iodd = []

    for k in range(len(v)):
        if k % 2:
            v_iodd.append(v[k])
        else:
            v_ieven.append(v[k])

    print(v_iodd)
    print(v_ieven)

    v_ieven.sort()
    v_iodd.sort()

    print(v_ieven)
    print(v_iodd)
    valid = True

    for l in range(len(v)-1):
        if l % 2:
            if v_iodd[(l-1)//2] > v_ieven[(l+1)//2]:
                valid = False
                error = l
                break
        else:
            if v_ieven[l//2] > v_iodd[l//2]:
                valid = False
                error = l
                break
    if valid :
        return "OK"
    else:
        return error



for case in range(int(input())):
    n = int(input())
    setN = input().split(' ')
    length = len(setN)
    result = findError(setN, length)
    if result == "OK":
        print('Case #%d: OK' % (case+1))
    else:
        print('Case #%d: %d' % (case+1, result))





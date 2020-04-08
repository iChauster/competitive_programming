import math

for case in range(int(input())):
    sessions, k = input().split()
    sessions = input().split()
    l = list()
    l.append(int(sessions[0]))
    for s in range(1, int(len(sessions))):
        l.append(int(sessions[s]) - int(sessions[s-1]))
    k = int(k)
    l.pop(0)
    while(k > 0):

        l.sort()
        
        sol = math.ceil(l.pop() / 2)

        l.append(sol)

        l.sort()

        print(l)

        k -= 1

    print('Case #%d: %s' % (case+1, l.pop()))
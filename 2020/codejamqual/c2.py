import collections

class Time():
    def __init__(self, time, state, index, end=None):
        self.time = time
        self.state = state
        self.index = index
        self.person = None
        self.nextState = end
    def setPerson(self, person):
        self.person = person

    def __repr__(self):
        return ("[%d %d %d %s]" % (self.time, self.state, self.index, self.person))

def solve() -> str:
    a = int(input())
    l = list()

    for x in range(a):
        first, second = [int(x) for x in input().split()]
        n = Time(first, 0, x)
        l.append(n)
        l.append(Time(second, 1, x, n))


    l.sort(key = lambda time:(time.time, -time.state))

    count = 0
    stack = ["C", "J"]
    for time in l:
        if time.state == 0:
            count += 1
            if count == 1:
                time.setPerson(stack.pop())
            elif count == 2:
                time.setPerson(stack.pop())
        else:
            count -= 1
            stack.append(time.nextState.person)
        if count > 2 :
            return "IMPOSSIBLE"

    l.sort(key = lambda time: time.index)
    pref = ""
    for time in l:
        if time.state == 0:
            pref += time.person
    return pref
    

for case in range(int(input())):
    print('Case #%d: %s' % (case+1, solve()))
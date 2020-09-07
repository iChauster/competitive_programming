import collections

def checkColl(c):
    for x in range(10):
        if x not in c:
            return False

    return True

def test(n):
    master = collections.defaultdict(int)
    if n == 0:
        return "INSOMNIA"
    else:
        counter = 1
        while not checkColl(master):
            num = collections.Counter(str(counter * n))
            for item in num.keys():
                master[int(item)] = 1
            counter += 1
        return n * (counter - 1)




for case in range(int(input())):
    number = int(input())
    print('Case #%d: %s' % (case+1, test(number)))
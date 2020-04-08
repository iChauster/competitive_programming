def getNumber(l, budget):
    able = 0
    afford = True
    while afford and len(l) > 0:
        element = l.pop()
        if (budget - element >= 0):
            budget -= element
            able += 1
        else :
            afford = False

    return able

for case in range(int(input())):
    houseNumber, budget = input().split()
    houses = input().split()
    l = list()
    for house in range(int(houseNumber)):
        l.append(int(houses[house]))
    l.sort(reverse = True)


    print('Case #%d: %s' % (case+1, getNumber(l, int(budget))))
def convertNumber(number):
    conversionArray = [(0,0), (1, 0), (1,1), (1,2), (3,1), (3,2), (3,3), (5,2), (7,1), (6,3)]
    a = ""
    b = ""
    for c in number:
        i = int(c)
        numberSet = conversionArray[i]

        a += str(numberSet[0])
        b += str(numberSet[1])

    return (a, b)

def trimNumber(number):
    counter = 0
    for c in number:
        if not c == "0" :
            break
        else:
            counter += 1

    return number[counter:]

for case in range(int(input())):
    number = str(input())
    returnedNumbers = convertNumber(number)
    firstN = trimNumber(returnedNumbers[0])
    secondN = trimNumber(returnedNumbers[1])
    print('Case #%d: %s %s' % (case+1, firstN, secondN))
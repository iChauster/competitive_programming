def getOpposite(string):
    newString = ""
    for c in string :
        if c == "S":
            newString += "E"
        else:
            newString += "S"
    return newString

for case in range(int(input())):
    number = int(input())
    lydiaMoves = str(input())
    print('Case #%d: %s' % (case+1, getOpposite(lydiaMoves)))
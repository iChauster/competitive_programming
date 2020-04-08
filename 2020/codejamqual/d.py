import collections
import math

def complement(y):
    x = y.copy()
    for i in range(len(x)):
        if x[i] != " ":
            x[i] = 0 if x[i] == 1 else 1
    return x

def reverse_bit(x):
    y = x.copy()
    y.reverse()
    return y
    

def three(x):
    return reverse_bit(complement(x))

def getsb(o, c, r, t) -> int:
    lz = [o,c,r,t]
    lz.sort(key=lambda x: x[0])
    for e in range(1, len(o)):
        if lz[0][e] != " " and lz[1][e] != " " and lz[2][e] != " " and lz[3][e] != " ":
            if lz[0][e] != lz[1][e] and lz[2][e] != lz[3][e]:
                return e + 1

    return 1

def countSolved(j):
    return len(j) - j.count(" ")

def getN(left, right, n):
    global totalBits  
    global l  
    global q

    #f.write("%d %d \n" % (left, right))
    for lInd in range(len(l)):
        if l[lInd] == " ":
            left = lInd + 1
            break

    for rInd in range(len(l) - 1, -1, - 1):
        if l[rInd] == " ":
            right = rInd + 1
            break
        

    #f.write("%d %d \n" % (left, right))


    for i in range(math.ceil(n)):
        print("%d" % (left + i))
        if l[left + i - 1] == " ":
            totalBits += 1
        l[left + i - 1] = int(input())

    leftBound = left + i - 1
    for i in range(math.floor(n)):        
        print("%d" % (right - i))
        if l[right - i - 1] == " ":
            totalBits += 1
        l[right - i - 1] = int(input())
    rightBound = right - i - 1

    q += 2*n
    totSublist = l

    r = reverse_bit(totSublist)
    c = complement(totSublist)
    t = three(totSublist)

    it = [totSublist, r, c, t]
    func = [None, reverse_bit, complement, three]
    res = list()
    bitsUsed = 0
    if r == totSublist or t == totSublist :
        print("%d" % 1)
        print("%d" % 1)
        throwaway = int(input())
        bitsUsed = 1
        res.append((0 , int(input())))
    else:
        print("%d" % 1)
        res.append((0,int(input())))

        idx = getsb(totSublist, c, r, t)
        #f.write("Significant bit: %d " % idx)
        print("%d" % idx)
        res.append((idx - 1,int(input())))
        bitsUsed = 2

    q += bitsUsed

    k = [j[0] for j in res]
    v = [j[1] for j in res]

    for x in range(len(it)):
        test = [it[x][key] for key in k]
        #f.write("testing for hits: \n %s vs. \n %s\n" % (test, v))
        if test == v:
            if func[x] is not None:
                #f.write("execute %d\n" % (x))
                l = func[x](l)
                break
            elif x == 0:
                #f.write("nothing happened \n")
                break


    if totalBits >= bits:
        print("".join([str(x) for x in l]))
        result = input()
        return
    else:
        #f.write("\n%s\n" % str(l))
        #f.write("Queries used %s, Solved: %d LB: %d, RB: %d \n\n\n\n" % (q, countSolved(l), leftBound, rightBound))
        getN(leftBound, rightBound, math.floor((10 - bitsUsed) / 2))


cases, bits = [int(x) for x in input().split()]
l = list()
f = open("output.txt", "w")    
for case in range(cases):
    #f.write("========== Case: %d" % (case + 1))
    l = [" "] * bits
    q = 0
    totalBits = 0
    getN(1, bits, 5)

    

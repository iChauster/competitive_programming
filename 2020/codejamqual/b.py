def solve() -> str:
    s = input()
    p1 = int(s[0])
    prefix = "" + "(" * p1
    prefix += str(p1)

    for x in range(1, len(s)):
        p2 = int(s[x])
        diff = p2 - p1
        if diff > 0:
            prefix += diff * "("
        elif diff < 0:
            prefix += abs(diff) * ")"
        prefix += str(p2)
        p1 = p2
    
    prefix += p1 * ")"

    return prefix 



for case in range(int(input())):
    print('Case #%d: %s' % (case+1, solve()))

from math import ceil

def aliens (m, o):

    def recFront(x, n, r, g):

        if flat(x, g) is True:
            x = x + 1

        res = flat(x+1, g)

        if res is True:
            if (x+1) < m:
                return recFront(int(ceil((n+x+1)/2)), n, x, g)
            else:
                return (x + 1)
        else:
            res = flat(x-1, g)
            if res is True:
                return (x-1)
            else:
                return recFront(int(((r+(x-1))/2)), r, x, g)

    frontX = recFront(int((m+o[0])/2), m, o[0], "x")
    frontY = recFront(int((m+o[1])/2), m, o[1], "y")

    print(frontX)
    print(frontY)

    def recBack(x, n, g):
        if flat(x, g) is True:
            x = x - 1
        res = flat(x-1, g)
        if res is True:
            if (x+1) < m:
                return recBack(int(ceil(x/2)), x, g)
            else:
                return (x+1)
        else:
            res = flat(x+1, g)
            if res is True:
                return (x+1)
            else:
                return recBack(int(ceil((n+x+1)/2)), x, g)


    backX = recBack(int((m+o[0]+1)/2), o[0], "x")
    backY = recBack(int((m+o[1]+1)/2), o[1], "y")

    mX = (backX + frontX)/2
    mY = (backY + frontY)/2

    return [mX, mY]
  

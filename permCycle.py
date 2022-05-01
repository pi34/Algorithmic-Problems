import math

def tiles (N, A):

    arr = []
    cycles = []
    queue = []
    counter = []
    currt = 0

    def add (n):
        if n is currt:
            counter.append(n)
            cycles.append(counter)
            counter = []
            return
        arr.remove(n)
        curr = A[n]
        counter.append(curr)
        queue.append(curr)

        add(curr-1)

    for i in arr:
        add()

        

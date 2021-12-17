def nextPerm(A):
    
    def binarySearch (A, start, end, value):

        if end >= start:

            mid = (end+start)//2

            if value < A[mid] and value >= A[mid-1]:
                return A[mid]

            elif A[mid] > value:
                return binarySearch(A, start, mid - 1, value)

            else:
                return binarySearch(A, mid + 1, end, value)

        else:
            return -1

    for i in range(len(A)-1, -1, -1):
        
        val = binarySearch(A[i::], 0, len(A)-i-1, A[i])

        if val != -1:
            new = A.pop(i)
            A[i] = val
            A.append(new)
            A[i+1::].sort()
            break

    return A

inp = list(map(int, input().split()))

L = []

for _ in range(inp[1]):
    L.append(list(map(int, input().split())))
    
for arr in L:
    print(' '.join(map(str, nextPerm(arr))))


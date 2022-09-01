import math

def pyramid (A):

    A.sort()

    curr = 0
    counter = 0

    for i in range(len(A)):
        prod = A[i]
        minim = min(prod)

        if minim >= curr:
            counter=counter+1

        if counter == curr+1:
            counter = 0
            curr = curr + 1
    
    return int((curr*(curr+1))/2)

N = int(input())
A = []

for _ in range(N):
    new = list(map(int, input().split()))
    new.sort()
    A.append(new)

print(pyramid(A))

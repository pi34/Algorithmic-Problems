  
def triathlon (N, A):

    newArr = []

    for i in range (N):

        first, second, third = A[i][0], A[i][1], A[i][2]
        ratio = (second + third) / first

        newArr.append([ratio, first, second, third, i])

    newArr.sort()

    sum = 0

    for i in range(N):
        sum = sum + newArr[i][1]

    sum = sum + newArr[-1][2] + newArr[-1][3]

    return sum

N = int(input())
A = []

for _ in range(N):
    new = list(map(int, input().split()))
    A.append(new)

print(triathlon(N, A))
 

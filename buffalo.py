A = [11, 7, 10, 9, 13, 14, 10, 15, 12, 10]
K = 5
l = K // 2
buyed = []
sell = []

def buy(n, var=False):
    if var is True:
        if n == len(A)-1:
            if A[n] > A[n-1]:
                var = False
                sell.append(A[n])
                return
            else:
                return

        elif n == 0:
            return

        if A[n] > A[n+1] and A[n] > A[n-1]:
            var = False
            sell.append(A[n])
            buy(n+1, var) 

        elif A[n] > A[n+1]:
            buy(n-1, var)

        elif A[n] > A[n-1]:
            buy(n+1, var)

    else:
        if n == 0:
            if A[n] < A[n+1]:
                var = True
                buyed.append(A[n])
                buy(n+1, var)
            else: 
                buy(n+1, var)

        elif n == len(A)-1:
            return

        elif A[n] < A[n+1] and A[n] < A[n-1]:
            var = True
            buyed.append(A[n])
            buy(n+1, var)
        
        elif A[n] < A[n+1]:
            buy(n-1, var)

        elif A[n] < A[n-1]:
            buy(n+1, var)

buy(0)

profits = []

for i in range(len(buyed)):
    profits.append(sell[i]-buyed[i])

print(sum(profits))

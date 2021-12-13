def roadTrip():

    for _ in range (int(input)):
        A = list(map(int, input().split()))
        N = A[0]
        M = A[1]
        K = A[2]

        adjMatrix = []

        for _ in range(N):
            adjMatrix.append([])

        for _ in range(M):
            curr = list(map(int, input().split()))
            adjMatrix[curr[0]].append(curr[1]-1)
            adjMatrix[curr[1]].append(curr[0]-1)

        NList = list(map(int, input().split()))
        MNList = []
        
        for x in range(N):
            MNList.append([NList[x], x])

        MNList.sort()

        l = 0
        n = 0
        i = 0

        marked = []

        tsum

        while i < (K//2):

            tsum = 0
            
            curr = MNList[i][1]
            arr = adjMatrix[curr]

            for item in arr:
                marked.append(item)
                tsum = tsum + NList[item]

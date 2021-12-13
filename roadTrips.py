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

        i = 0
        dones = 0

        marked = []

        tsum = 0

        while i < (K//2):

            if i not in marked:

                curr = MNList[i][1]
                arr = adjMatrix[curr]

                tsum = tsum + curr[0]

                for item in arr:
                    marked.append(item)
                    tsum = tsum + NList[item]

                dones = dones + 1

            if len(MNList)-i not in marked:

                curr = MNList[len(MNList)-i][1]
                arr = adjMatrix[curr]

                tsum = tsum + curr[0]

                for item in arr:
                    marked.append(item)
                    tsum = tsum + NList[item]

                dones = dones + 1

        if dones < K:
            return -1
        else:
            return tsum

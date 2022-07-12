import math

num=37
numroot=int(math.sqrt(num))
notprime=True

for i in range(num,1,-1):
    #print(i)
    if num%i==0: 
        rooti=int(math.sqrt(i))
        #print(rooti)
        if (rooti <= 2):
            notprime=False
        for k in range(2,rooti+1): 
            #print(k)
            if i%k==0:
                notprime=True
                break
            else:
                notprime=False    
    if notprime==False:
        print(i)
        break

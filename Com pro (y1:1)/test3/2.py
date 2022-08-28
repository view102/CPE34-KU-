def createmaze(n,t):
    size=2*n-1
    lists=[]
    for i in range(size//2 + 1):
        row=[]
        for j in range(size):
            row.append('')
        lists.append(row)
    #print(lists)
    if t == 1:
        even=n//2
        odd=n-even
        maxx=max(even,odd)
        minn=min(even,odd)
        if n%2!=0:
            x=maxx
        else:
            x=minn
        num=1
        pos=0
        pos2=0
        times=0
        for k in range(n):
            for i in range(pos,n):
                for j in range(pos,size-pos):
                    lists[pos2][j]=num
                pos2+=1
            num+=2
            pos+=1
            times+=1
            pos2=pos
            if times==x:
                num=2
        for i in range(len(lists)-2,-1,-1):
            lists.append(lists[i])
    elif t == 2:
        even=n//2
        odd=n-even
        maxx=max(even,odd)
        minn=min(even,odd)
        if n%2!=0:
            x=minn
        else:
            x=maxx
        num=2
        if n==1:
            num=1
        pos=0
        pos2=0
        times=0
        for k in range(n):
            for i in range(pos,n):
                for j in range(pos,size-pos):
                    lists[pos2][j]=num
                pos2+=1
            num+=2
            pos+=1
            times+=1
            pos2=pos
            if times==x:
                num=1
        for i in range(len(lists)-2,-1,-1):
            lists.append(lists[i])
    return lists

def printmaze(m):
    for i in range(len(m)):
        for j in range(len(m[i])):
            print(m[i][j],end=' ')
        print()



n=int(input("Input the maze's size (only 1 to 9): "))
types=int(input('Input the type of maze (only 1 to 2): '))
printmaze(createmaze(n,types))

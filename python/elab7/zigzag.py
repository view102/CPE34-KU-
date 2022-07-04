def zigzag(s,n):
    s=list(s)
    count=0
    rcount=n-2
    zz=[]
    for i in range(n):
        row=[]
        zz.append(row)
    for i in range(len(s)):
        if count<n-1:
            zz[count].append(s[i])
            count+=1
        elif count==n-1:
            zz[count].append(s[i])
            count+=1
            rcount=n-2
        elif rcount>0:
            zz[rcount].append(s[i])
            rcount-=1
        elif rcount==0:
            zz[rcount].append(s[i])
            rcount-=1
            count=1
    return zz

def printtext(s):
    tx=''
    for i in range(len(s)):
        for j in range(len(s[i])):
            tx=tx+s[i][j]
    print(tx)

text='WeAreTheChampion'
n=4
zz=zigzag(text,n)
print(zz)
printtext(zz)
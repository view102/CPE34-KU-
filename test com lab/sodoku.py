def readMiniSodoku(fn):
    with open(fn) as f:
        r=f.readlines()

    sdktmp=[]
    for i in r:
        row=[]
        for j in i.strip().split(','):
            row.append(j)
        sdktmp.append(row)

    return sdktmp

def sodoku(s,n):
    x=0
    count=0
    b=s[:n]
    sd=[]
    for i in range(n):
        sd.append([])
    for i in range(len(b)):
        for j in range(len(b[i])):
            #print(j)
            if j in range(x*n,n*(x+1)):
                #print(x,j)
                sd[x].append(b[i][j])
                #print(sd[x])
                count+=1
                if count == n:
                    x+=1
                    count=0
        x=0
    if len(s)==0:
        return []    
    return sd + sodoku(s[n:],n)


fn='Minisodoku01.txt'
s= readMiniSodoku(fn)
n=int(len(s)**(1/2))
#print(s[:3])
#print(s)
y=sodoku(s,n)
print(y)
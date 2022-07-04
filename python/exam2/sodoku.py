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

def printsubgrid(b):
    len_b=len(b)**(1/2)
    for i in range(int(len_b)):
        for j in range(int(len_b)):
            #print(j)
            print(f'{b[j]:3}',end='')
        b=b[int(len(b)**(1/2)):]
        #print(b)
        print()

def checkMiniSodoku(s):
    n=int(len(s)**(1/2))
    sdk=sodoku(s,n)
    #print(sdk)
    for i in range(len(sdk)):
        for j in range(len(sdk[i])):
            if sdk[i].count(str(j)) > 1:
                #print(j)
                b=sdk[i]
                print('Subgrid')
                printsubgrid(b)
                print('fails test#1!')
                return False
    for i in range(0,len(sdk)):
        a=sdk[i]
        error=0
        for j in sdk:
            #print(sdk[i-1],sdk[i])
            if a == j:
                error+=1
                #print(i)
                if error >1:
                    b=a.copy()
                    print('Subgrid')
                    printsubgrid(b)
                    print('fails test#2!')
                    return False
    return True


def printMiniSodoku(a):
    res, n = '', len(a)
    for i in range(n):
        for j in range(n):
            res+=f'{a[i][j]:3}'
        if i < n-1:
            res+='\n'
    print(res)

#fn = 'Minisodoku01.txt'
fn = input('Enter minisodoku0x.txt: ')
s = readMiniSodoku(fn)
print('running miniSodoku')
printMiniSodoku(s)
res = checkMiniSodoku(s)
print(res)
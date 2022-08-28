A='A.txt'
B='B.txt'
C='C.txt'
def readmat(x):
    with open(x) as f:
        mat=[]
        r=f.readlines()
        #print(r)
        for i in r:
            row=[]
            for j in i.strip().split():
                row.append(float(j))
            mat.append(row)
    return mat

def plus(x,y):
    mat=[]
    for i in range(len(x)):
        row=[]
        for j in range(len(x[i])):
            result=x[i][j]+y[i][j]
            row.append(float(f'{result:.2f}'))
        mat.append(row)
    return mat

def trans(x):
    mat=[]
    for i in range(len(x[0])):
        row=[]
        for j in range(len(x)):
            row.append(float(f'{x[j][i]:.2f}'))
        mat.append(row)
    return mat

def minus(x,y):
    mat=[]
    for i in range(len(x)):
        row=[]
        for j in range(len(x[i])):
            result=float(x[i][j])-float(y[i][j])
            row.append(float(f'{result:.2f}'))
        mat.append(row)
    return mat

def mul(x,y):
    #print(x,y)
    mat=[]
    for i in range(len(x)):
        row = []
        for j in range(len(x[i])):
            total=0
            for k in range(len(y)):
                total+=x[i][k]*y[k][j]
            row.append(float(f'{total:.2f}'))
        mat.append(row)
    return mat

def mul_constant(x,c):
    for i in range(len(x)):
        for j in range(len(x[i])):
            x[i][j] = float(f'{(x[i][j]*c):.2f}')
    return x

def power(x,c):
    mat=[]
    tmp=x.copy()
    for i in range(c-1):
        tmp=mul(tmp,x)
    mat=tmp.copy()
    return mat

def printmat(mat):
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            x=mat[i][j]
            #print(x)
            print(f'{x}',end=' ')
        print()

z=[[1,2,3],[2,3,4],[1,1,1]]
a=readmat(A)
b=readmat(B)
c=readmat(C)
#print(a,b,c)
#print(mul(z,z))
first=mul(c,plus(trans(c),mul_constant(a,2)))
printmat(first)
print()
second=minus(trans(mul(a,b)),c)
printmat(second)
print()
third=power(b,3)
printmat(third)
print()
fourth=plus(trans(a),mul_constant(c,7))
printmat(fourth)
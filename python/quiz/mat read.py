def readmat(mat):
    with open(mat) as f:
        r=f.readlines()
    op=[]
    count=0
    read=[]   
    mat=[]
    for i in r:
        row=[]
        for j in i.strip().split():
            if j != "" and j not in ['+','*']:
                row.append(int(j))
            else:
                read.append(mat)
                read.append(j)
                op.append(j)
                mat=[]
        if len(row)!= 0:
            mat.append(row)
    read.append(mat)
    return read,op

def plus(A,B):
    C=[ [A[i][j]+B[i][j] for j in range(len(B)) ]for i in range(len(A))]
    return C

def mul(A,B):
    C=[ [ sum( A[i][k] * B[k][j] for k in range(len(A[0]))) for j in range(len(B[0]))] for i in range(len(A)) ]
    return C


start=0
mat='matrix.txt'
r,op=readmat(mat)
res=[]
#print(r)
#print(mul(r[0],r[1]))
for i in range(len(r)):
    if r[i] in ['*','+','-']:
        res.append(i)

for i in range(len(op)):
    #print(op[i])
    if op[i] == '*' and start==0:
        pos=res[i]
        #print(pos)
        mat=mul(r[pos-1],r[pos+1])
        start+=1
    elif op[i] == '*':
        pos=res[i]
        mat=mul(r[pos-1],r[pos+1])
        start+=1

for i in range(len(op)):
    if op[i] in ['+','-']:
        pos=res[i]
        mat=plus(mat,r[pos+1])
        
'''
1 2 3 4 5
6 7 8 9 10

11 12 13 14 15
*
1   2  3
4   5  6
7   8  9
10 11 12
13 14 15
+
1 0 0
0 1 0
0 0 1
'''

#print(plus(mul(r[0],r[1]),r[2]))
print(mat)

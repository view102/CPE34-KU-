import math
n = int(input("Material size: "))
a = list()
qs = [[0]*n for _ in range(n)]
for i in range(n):
    x = list(map(int,input().split()))
    a.append(x)
#set Qs
qs[0][0] = a[0][0]
for i in range(1, n) : 
    qs[0][i] = (qs[0][i - 1] + a[0][i]) 
    qs[i][0] = (qs[i - 1][0] + a[i][0])
     
for i in range(1,n):
    for j in range(1,n):
        qs[i][j] = (qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1] + a[i][j]) 

neww = [[0]*(n-2) for _ in range(n-2)]
for i in range(2,n):
    for j in range(2,n):
        if j-3<0  : 
            aa = 0
        else : 
            aa = qs[i][j-3]
        if i-3<0 : 
            bb = 0
        else : 
            bb = qs[i-3][j]
        
        if (aa == 0 and bb!= 0) or (bb == 0 and aa!= 0) :
        
            neww[i-2][j-2] = float((qs[i][j]-aa-bb )/9)
        elif aa == 0 and bb==0:
     
            neww[i-2][j-2] = float((qs[i][j])/9)
        else :
            neww[i-2][j-2] = float((qs[i][j]-aa-bb+qs[i-3][j-3] )/9)
con = [[False]*6]
s= len(neww)
c1 = [85,70,60]
c2 = [90,85,70]
c3 = [70,60,0]
ans = ['Grade A','Grade B','Grade C','Grade A (Upgrade From B)','Grade B (Upgrade From C)','Grade C (Upgrade From No Grade)']
percent = n*n/4

check = True
for k in range(3):
    d1 = True
    d2 = True
    count = 0 
    for i in range(s):
        for j in range(s):
            if neww[i][j] < c1[k]:
                d1 = False 
            if neww[i][j] < c3[k]:
                d2 = False 
    if (d1) : 
        print(f"Output: {ans[k]}")
        check = False
        break
    for i in range(n):
        for j in range(n):
            if a[i][j] >= c2[k]: count+=1
 
    if d2 and count >= percent:
        print(f"Output: {ans[3+k]}")
        check = False
        break
    
if check : print("Output: No Grade")



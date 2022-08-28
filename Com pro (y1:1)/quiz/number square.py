n = int(input(''))
row = 2*n - 1
num = []
for i in range(n+1):
  num.append([])
len_num=len(num)
#print(num)
nn=n
tmp=n
pos=0
pos2=-1
for i in range(len_num-1):
  for j in range(row):
    num[i].append(n)
  n-=1
#for i in range(1,len_num-1):
  for j in range(i):
    num[i][pos]=tmp
    num[i][pos2]=tmp
    pos+=1
    pos2-=1
    tmp-=1
  tmp=nn
  #print(tmp)
  pos=0
  pos2=-1
  #print(pos,pos2)
num.pop(-1)
for i in range(nn-2,-1,-1):
  num.append(num[i])
#print(num)
for i in range(len(num)):
  for j in range(len(num[i])):
    print(num[i][j],end=' ')
  print()

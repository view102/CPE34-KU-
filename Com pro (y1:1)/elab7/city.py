b=[]
c=input("City Size: ").split(" ")
for i in range(int(c[0])):
  r=input("").split(" ")
  b.append(r)
#print(b)
v=['N','S','E','W']
nv=[]
for i in range(4):
  sum=0
  if v[i]=='N':
    for j in range(int(c[1])):
      for k in range(int(c[0])):
        if k==0:
          #print(b[k][j])
          num=b[k][j]
          sum+=1
        else:
          if b[k][j]>num:
            #print(b[k][j])
            num=b[k][j]
            sum+=1
    nv.append(sum)
  elif v[i]=='S':
    for j in range(int(c[1])):
      for k in range(int(c[0])-1,-1,-1):
        if k==int(c[0])-1:
          num=b[k][j]
          #print(b[k][j])
          sum+=1
        else:
          if b[k][j]>num:
            sum+=1
            num=b[k][j]
            #print(b[k][j])
    nv.append(sum)

  elif v[i]=='E':
    for j in range(int(c[0])):
      for k in range(int(c[1])-1,-1,-1):
        #print(k)
        if k == int(c[1])-1:
          sum+=1
          #print(b[j][k])
          num = b[j][k]
          #print(sum,'/')
        else:
          if b[j][k]>num:
            #print(b[j][k])
            num=b[j][k]
            sum+=1
            #print(sum,"/")
    nv.append(sum)

  elif v[i]=='W':
    for j in range(int(c[0])):
      for k in range(int(c[1])):
        #print(k)
        if k == 0:
          sum+=1
          #print(b[j][k])
          num = b[j][k]
          #print(sum,'/')
        else:
          if b[j][k]>num:
            #print(b[j][k])
            num=b[j][k]
            sum+=1
            #print(sum,"/")
    nv.append(sum)
#print(nv[0],nv[1],nv[2],nv[3])
maxb=max(nv)
for i in range(len(v)):
  if nv[i]==maxb:
    print(v[i],end=' ')



#print(b)
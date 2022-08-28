def readfile(files):
  with open(files, 'r') as f:
    r=f.readlines()
  
  read=[]
  for i in r:
    for j in i.strip().split(','):
      read.append(j)
  f.close()
  return read ,r

def countfile(a):
  sum=0
  title=[]
  b=[]
  for i in a:
    if i<'999999999999' and i>='0':
      b.append(i)
    elif i in a[:39]:
      title.append(i)
      #print(i)
      sum+=1
    else:
      b.append(i)
  return title, b, sum

def first():
  print(len_rr)

def second(title,c,uids):
  mymax=-99999999999999
  view=[]
  for j in range(c-2):
    sum=0
    for i in range(len(rr)-1):
      sum += int(uids[i][j])
    #print(sum)
    if sum>mymax:
      mymax=sum
      res=j
    view.append(sum)

  for i in range(len(view)):
    if view[i]==mymax:
      print(title[i])
  return

def thrid():
  bp=[]
  for i in range(len_title):
    if title[i] == 'blueplanet':
      res=i
  #print(res)
  for i in range(len_rr-1):
    bp.append(uids[i][res])
  #print(type(bp[0]))
  for i in range(len(bp)):
    bp[i]=int(bp[i])
  for i in range(3):
    print(max(bp),end=" ")
    bp.remove(max(bp))

def fourth():
  maxuser=[]
  for i in range(len_rr-1):
    b=uids[i][:37]
    #print(b)
    #print(b)
    for i in range(len(b)):
      b[i]=int(b[i])
    maxuser.append(sum(b))
  #print(maxuser)
  print(uids[maxuser.index(max(maxuser))][37],max(maxuser))

def fifth():
  mymax=-999999999
  for i in range(len_rr-1):
    x=int(uids[i][0])
    #print(x)
    if x>mymax:
      mymax=x
      res=i
  print(uids[res][-1],mymax)

def sixth():
  sum=0
  for i in range(len_title):
    if title[i] == 'korea':
      res=i
  for i in range(len_rr-1):
    x=int(uids[i][res])
    if x > 500:
      sum+=1
  print(sum)

def seventh():
  sum=0
  for i in range(len_title):
    if title[i] == 'siam':
      res1=i
    if title[i] == 'food':
      res2=i
  for i in range(len_rr-1):
    x=int(uids[i][res1])
    y=int(uids[i][res2])
    if x > y:
      sum+=1
  print(sum)

def eighth():
  mypmax=-1
  myz=[]
  for i in range(len_title):
    if title[i] == 'rajdumnern':
      res1=i
  for i in range(len_rr-1):
    #print(i)
    for j in range(1):
      b=uids[i][:37]
      x=int(uids[i][res1])
      for k in range(len(b)):
        b[k]=int(b[k])
      y=sum(b)
      #print(x,y)
      z=x*100/y
      if z>mypmax:
        mypmax=z
    myz.append(z)
  #print(myz)
  print(uids[myz.index(max(myz))][-1])
      #print(b)
      #print(j,end=" ")
    #print()

def ninth():
  tt=0
  for i in range(len_rr-1):
    b=uids[i][:len(uids[1])-1]
    #print(b)
    for j in range(len(b)):
      b[j]=int(b[j])
    z=sum(b)
    x=max(b)
    b.remove(max(b))
    y=max(b)
    per=(x+y)*100/z
    if per>70:
      tt+=1
  print(tt)


def tenth():
  sum=0
  for i in range(len_title):
    if title[i] == 'pantip':
      res1=i
  for i in range(len(rr)-1):
    if int(uids[i][res1]) == 0:
      sum+=1
  print(sum)

files=input("File name: ")
n=int(input("enter number: "))
r,rr=readfile(files)
title, user, c = countfile(r)
uids=[]
#for i in range(len(user)//c):
 # uids.append([])
len_user=len(user)
#for i in range(len_user//c):
 # b=user[i*c:]
  #uids.append([])
  #for j in range(c):
   # uids[i].append(b[j])
resid=0
resid2=0
for i in range(len_user):
  uids.append([])
  uids[resid].append(user[i])
  resid2+=1
  if resid2==c:
    resid+=1
    resid2=0
len_rr=len(rr)
len_title=len(title)
if n==1:
  first()
elif n==2:  
  second(title,c,uids)
elif n==3: 
  thrid()
elif n==4: 
  fourth()
elif n==5: 
  fifth()
elif n==6: 
  sixth()
elif n==7: 
  seventh()
elif n==8: 
  eighth()
elif n==9: 
  ninth()
elif n==10: 
  tenth()
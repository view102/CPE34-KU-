import json

def readfile(f):
  tx=''
  line=[]
  with open(f) as f:
    r=f.readlines()
  for i in r:
    #print(i)
    line.append(json.loads(i))
  #j=json.loads(r)
  return line

def first(r):
  return print(len(r))

def second(r):
  user=[]
  for row in r:
    if row['reviewerID'] not in user:
      user.append(row['reviewerID'])
    else:
      pass
  return print(len(user))

def third(r):
  item=[]
  for row in r:
    if row['productName'] not in item:
      item.append(row['productName'])
  return print(len(item))

def fourth(r):
  c=[]
  for row in r:
    cate=row['category'].split('>')
    if cate[0] not in c:
      c.append(cate[0])
    else:
      pass
  return print(len(c))

def fifth(r):
  c=[]
  for row in r:
    cate=row['category'].split('>')
    if cate[1] not in c:
      c.append(cate[1])
    else:
      pass
  return print(len(c))

def sixth(r):
  user={}
  name=''
  mymax=-999999
  for row in r:
    if row['reviewerID'] not in user.keys():
      user[row['reviewerID']] = 0
    else:
      user[row['reviewerID']] += 1
      if user[row['reviewerID']] > mymax:
        mymax = user[row['reviewerID']]
        name = row['reviewerID']
  return print(name)

def seventh(r):
  review={}
  mymax=-999
  name=''
  for row in r:
    if row['productName'] not in review.keys():
      review[row['productName']] = [row['overall'],1]
    else:
      review[row['productName']][0] += row['overall']
      review[row['productName']][1] += 1
  for key in review.keys():
    review[key][0] = review[key][0]/review[key][1]
  for key in review.keys():
    if review[key][0] > mymax:
      mymax=review[key][0]
      name=key
  res=[]
  for key in review.keys():
    if review[key][0] == mymax:
      res.append(key)
  
  if len(res) > 1:
    mymax=-1
    for key in res:
      if review[key][1] > mymax:
        mymax=review[key][1]
        name=key
  #print(len(res))
  return print(name)
  

def eighth(r):
  review={}
  mymax=-1
  name=''
  for row in r:
    listx=[]
    for x in row['reviewText'].strip().split(" "):
      listx.append(x)
    #print(len(listx))
    if row['productName'] not in review.keys():
      review[row['productName']] = [len(listx),1]
    else:
      review[row['productName']][0] += len(listx)
      review[row['productName']][1] += 1

  for key in review.keys():
    review[key][0] = review[key][0]/review[key][1]
      #print(review[key][0])
    if review[key][0] > mymax:
      mymax = review[key][0]
      name = key
  return print(name)

file=input('file name: ')
r=readfile(file)
#print(r)
n=int(input("input: "))
if n==1:
  first(r)
elif n==2:
  second(r)
elif n==3:
  third(r)
elif n==4:
  fourth(r)
elif n==5:
  fifth(r)
elif n==6:
  sixth(r)
elif n==7:
  seventh(r)
elif n==8: 
  eighth(r)
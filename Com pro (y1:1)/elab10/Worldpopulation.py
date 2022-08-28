import json

def readfile(f):
  with open(f) as f:
    r=f.read()
  
  j=json.loads(r)

  return j

def first(r):
  country=[]
  for i in range(len(r)):
    country.append(r[i]['country'])
  return print(len(country))

def second(r):
  total=0
  for row in r:
    total+=int(row["population"])
  return print(total)

def third(r):
  countryC=[]
  country5=[]
  for row in r:
    if row['country'][0] == 'C':
      countryC.append(row['country'])
    if len(row['country']) > 5:
      country5.append(row['country'])
  return print(f'{len(countryC)}\n{len(country5)}')

def fourth(r):
  fivemillion=0
  twohunfifty_sevenfifty=0
  undertenmillion=0
  for row in r:
    n=int(row['population'])
    if n > 500000000:
      fivemillion+=1
    if n>250000000 and n<750000000:
      twohunfifty_sevenfifty+=1
    if n<10000000:
      undertenmillion+=1
  return print(f'{fivemillion}\n{twohunfifty_sevenfifty}\n{undertenmillion}')  

def swap(a,i,j):
  tmp=a[i]
  a[i]=a[j]
  a[j]=tmp

def fifth(r):
  country=[]
  population=[]
  fiftyth=[]
  for row in r:
    country.append(row['country'])
    population.append(float(row['World']))
  b=population[:20]
  a=population[49:150]
  x=sum(b)*100
  y=sum(a)*100
  return print(f'{x:.2f}\n{y:.2f}')
  

file=input("File Name: ")
r=readfile(file)
#print(type(r[0]))
n=int(input("Input : "))
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


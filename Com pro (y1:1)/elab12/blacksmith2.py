def avg(s):
  pos1=0
  pos2=2
  pos3=0
  pos4=2
  n=(len(s)-3+1)
  avg=[]
  total=0
  for _ in range(n):
    for a in range(n):
      total=0
      for i in range(pos1,pos2+1):
        for j in range(pos3,pos4+1):
          total+=s[i][j]
      avg.append(float(f'{total/(n*n):.2f}'))
      pos3+=1
      pos4+=1
    pos1+=1
    pos2+=1
    pos3=0
    pos4=2
  return avg

def inputFE(size):
  fe=[[row for row in input().split(' ')] for i in range(size)]
  for i in range(len(fe)):
    for j in range(len(fe[0])):
      fe[i][j] = int(fe[i][j])
  return fe

def checkgrade(avg,fe):
  dict1={'C':60,'B':70,'A':85}
  grade=['No Grade','C','B','A']
  pos=0
  for g in dict1.keys():
    for i in range(len(avg)):
      if avg[i] >= dict1[g]:
        pass
      else:
        return grade[pos]
    pos+=1
  return 'A'

def upgrade(s,grade):
  if grade == 'A':
    return 'Grade ' + grade
  dict1={'No Grade':70,'C':85,'B':90}
  g=['No Grade','C','B','A']
  res = g.index(grade)
  n=0
  total=len(s)*len(s[0])
  for i in range(len(s)):
    for j in range(len(s[0])):
      if s[i][j] >= dict1[grade]:
        n+=1
  percent=(n*100)/total
  if percent > 25:
    return 'Grade ' + g[res+1] + f' (Upgrade From {grade})'
  elif grade != 'No Grade':
    return 'Grade ' + grade
  else:
    return grade 

size=int(input("Material size: "))
fe=inputFE(size)
#print(fe)
avg=avg(fe)
#print(avg)
grade=checkgrade(avg,fe)
#print(grade)
upgrade=upgrade(fe,grade)
#print(upgrade)
print(f'Output: {upgrade}')
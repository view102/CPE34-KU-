def input_matrix():
    data = []
    for i in range(3):
        data.append([int(j) for j in input(f"Row {i+1} : ").split(' ')])
    return data

def avg(s):
  ns=len(s)-3+1
  r=ns*ns
  pos1=0
  pos2=2
  pos3=0
  pos4=2
  time=0
  ss=[]
  for i in range(r):
    row=[]
    a=[]
    total=0
    n=0
    for j in range(pos3,pos4+1):
      b=s[j][pos1:pos2+1]
      a.append(b)
    for j in range(len(a)):
      for k in range(len(a[j])):
        total+=a[j][k]
        n+=1
    #print(a)
    ss.append(float(f'{total/n:.2f}'))
    pos1+=1
    pos2+=1
    time+=1
    if time == ns:
      time=0
      pos3+=1
      pos4+=1
      pos1=0
      pos2=2
  return ss

def upgrade(s,grade):
  dict1={'A':90, 'B':85, 'C':70, 'No grade':0}
  total=0
  for i in range(len(s)):
    for j in range(len(s[i])):
      if s[i][j] >= dict1[grade]:
        total+=1
  percent=total/(len(s)*len(s[0]))*100
  if percent > 25:
    return True
  else:
    return False


def checkgrade(avg,s):
  a=0
  b=0
  c=0
  no=0
  for i in range(len(avg)):
    if avg[i] >= 85:
      a+=1
    elif avg[i] >= 70:
      b+=1
    elif avg[i] >= 60:
      c+=1
    elif avg[i] < 60:
      no+=1
  #print(a,b,c,no)
  if no != 0:
    if upgrade(s,'C'):
        return 'Grade C (Upgrade From No Grade)'
    else:
        return 'No Grade'
  if c != 0:
    if upgrade(s,'B'):
        return 'Grade B (Uspgrade From C)'
    else:
        return 'Grade C'
  if b != 0:
    if upgrade(s,'A'):
        return 'Grade A (Upgrade From B)'
    else:
        return 'Grade B'
  if a != 0:
    return 'Grade A'

      
   


size = int(input("Material size: "))
fe = [[int(row) for row in input("").split(" ")] for i  in range(size)]
#print(fe)
#a=[[74,94,95,64,56],[65,91,66,76,80],[82,71,90,75,59],[59,63,84,70,90],[95,79,92,69,73]]
feavg=avg(fe)
#u=upgrade(a,'A')
g=checkgrade(feavg,fe)
#print(u)
#print(feavg)
print('Output:',g)
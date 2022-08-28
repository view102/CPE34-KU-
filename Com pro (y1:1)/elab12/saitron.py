def move(st,count,status,i,j):
  #print(i,j,' ',count,status)
  if status=='right':
    while j < len(st[i])-1:
      j+=1
      if st[i][j] == '\\' or st[i][j] == '/':
        count+=1
        if st[i][j] == '\\':
          return move(st,count,'down',i,j)
        else:
          return move(st,count,'up',i,j)
    return 2**count
  elif status == 'left':
    while j > 0:
      j-=1
      if st[i][j] == '\\' or st[i][j] == '/':
        count+=1
        if st[i][j] == '\\':
          return move(st,count,'up',i,j)
        else:
          return move(st,count,'down',i,j)
    return 2**count
  elif status == 'up':
    while i > 0:
      i-=1
      if st[i][j] == '\\' or st[i][j] == '/':
        count+=1
        if st[i][j] == '\\':
          return move(st,count,'left',i,j)
        else:
          return move(st,count,'right',i,j)
    return 2**count
  elif status == 'down':
    while i < len(st)-1:
      i+=1
      if st[i][j] == '\\' or st[i][j] == '/':
        count+=1
        if st[i][j] == '\\':
          return move(st,count,'right',i,j)
        else:
          return move(st,count,'left',i,j)
    return 2**count


saitron=' '
st=[]
while saitron != '':
  saitron=input()
  tmp=saitron.split(' ')
  if saitron != '':
    st.append(tmp)
#print(saitron)
count=1
max_saitron=-1
for i in range(len(st)):
  for j in range(len(st[i])):
    if st[i][j] == '\\' or st[i][j] == '/':
      if st[i][j] == '\\':
        max_saitron=max(max_saitron,move(st,count,'down',i,j))
      else:
        max_saitron=max(max_saitron,move(st,count,'up',i,j))
      break

for i in range(len(st)):
  for j in range(len(st[i])-1,-1,-1):
    if st[i][j] == '\\' or st[i][j] == '/':
      if st[i][j] == '\\':
        max_saitron=max(max_saitron,move(st,count,'up',i,j))
      else:
        max_saitron=max(max_saitron,move(st,count,'down',i,j))
      break

for i in range(len(st[0])):
  for j in range(len(st)):
    if st[j][i] == '\\' or st[j][i] == '/':
      if st[j][i] == '\\':
        max_saitron=max(max_saitron,move(st,count,'right',j,i))
      else:
        max_saitron=max(max_saitron,move(st,count,'left',j,i))
      break

for i in range(len(st[0])):
  for j in range(len(st)-1,-1,-1):
    if st[j][i] == '\\' or st[j][i] == '/':
      if st[j][i] == '\\':
        max_saitron=max(max_saitron,move(st,count,'down',j,i))
      else:
        max_saitron=max(max_saitron,move(st,count,'up',j,i))
      break

print('Maximum saitron is',max_saitron,'particle(s)')
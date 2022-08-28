hj=[]
tmp = True

while tmp:
  s = [row for row in input("").split(" ")]
  if s != ['']:
    hj.append(s)
  else:
    tmp = not tmp

for i in range(len(hj)):
  for j in range(len(hj[i])):
    hj[i][j] = int(hj[i][j])
#print(hj)

for i in range(len(hj)-1):
  if len(hj[i]) == len(hj[i+1]):
    check = True
  else:
    check = False
#print(check)
minbuy=99999999999
if check:
  for i in range(len(hj)-1):
    for j in range(len(hj[i])-1):
      minbuy=min(minbuy, hj[i][j] + hj[i][j+1]*1.1 + hj[i+1][j+1]*1.1 + hj[i+1][j]*1.1*1.1)

  for i in range(len(hj)-1,0,-1):
    for j in range(len(hj[i])-1):
      minbuy=min(minbuy, hj[i][j] + hj[i][j+1]*1.1 + hj[i-1][j+1]*1.1 + hj[i-1][j]*1.1*1.1)
  print(f'{minbuy:.2f}')
else:
  print('Can\'t Buy')
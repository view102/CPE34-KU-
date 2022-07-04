def printstar(s):
  for i in range(len(s)):
    for j in range(len(s[i])):
      print(s[i][j],end="")
    print()

n = int(input("n: "))
star=[]
for i in range(n//2 + 1):
  row=[]
  for j in range(n):
    row.append(' ')
  star.append(row)
for i in range(n):
  star[-1][i] = '+'
for i in range(n//2 + 1):
  star[i][n//2] = '+'
pos1=0
pos2=-1
for i in range(n//2):
  star[i][pos1] = '+'
  star[i][pos2] = '+'
  pos1+=1
  pos2-=1
for i in range(len(star)-2,-1,-1):
  star.append(star[i])
printstar(star)
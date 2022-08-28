n=int(input('Input n: '))
m=int(input('Input m: '))
total=n*m
lists=[]
pos=[]
for i in range(n):
    um=input().split(" ")
    for j in range(len(um)):
        um[j] = int(um[j])
    lists.append(um)
#print(lists)
for i in range(1,total+1):
    for j in range(len(lists)):
        for k in range(len(lists[j])):
            if lists[j][k] == i:
                res=f'({j},{k})'
    pos.append(res)
for i in pos:
    print(i)

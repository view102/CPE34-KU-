def hanabi(type,m):
    hnb=[]
    if type == 1:
        for i in range(m//2+1):
            row=[]
            for j in range(m):
                row.append(' ')
            hnb.append(row)
        for i in range(m):
            hnb[-1][i] = 1 
        pos=0
        for i in range(m//2):
            #print(i)
            hnb[i][m//2] = 1
            hnb[i][pos] = 1
            hnb[i][-pos-1] = 1
            pos+=1
        for i in range(len(hnb)-2,-1,-1):
            hnb.append(hnb[i])
        #printhnb(hnb)
    else:
        n=2*m-1
        num=m-1
        for i in range(m):
            row=[]
            for j in range(n):
                row.append(m)
            hnb.append(row)
        pos1=1
        time=len(hnb[0])-1
        for _ in range(4):
            for i in range(pos1,len(hnb)):
                for j in range(pos1,time):
                    hnb[i][j] = num
            pos1+=1
            time-=1
            num-=1
        for i in range(len(hnb)-2,-1,-1):
            hnb.append(hnb[i]) 
        #printhnb(hnb)
    return hnb

def printhnb(hnb):
    for i in range(len(hnb)):
        for j in range(len(hnb[i])):
            print(hnb[i][j],end='')
        print()

#Example type ฟังก์ชั่นสามารถหาพลุได้
printhnb(hanabi(1,5))
printhnb(hanabi(2,5))

#maincode
sky=[]
Sky=int(input("Sky : "))
Hanabi=int(input('Hanabi : '))
position=[]
hnb=[]
for i in range(Hanabi):
    s=input().split(' ')
    position.append(s)
for i in range(Sky):
    row=[]
    for j in range(Sky):
        row.append('.')
    sky.append(row)
for i in range(len(position)):
    if int(position[i][2]) == 1:
        #หาพิกัดกึ่งกลางพลุ
        sky[int(position[i][0])][int(position[i][1])] = 1
        hnb=hanabi(1,int(position[i][3]))
        #พยายามสร้างเพิ่มครับเเต่ไม่ทันเเล้ววว
        #pos1=int(position[i][0])
        #pos2=pos1
        #pos=int(position[i][1])
        #n=int(position[i][3])//2
        #while n>0 and pos1>0 and pos1<len(sky)-1 and pos2>0 and pos2<len(sky)-1:
            #sky[pos1][pos] = 1
            #sky[pos2][pos] = 1
            #pos1+=1
            #pos2-=1

    else:
        #หาพิกัดกึ่งกลางพลุ
        sky[position[0]][position[1]] = 1
        hnb=hanabi(2,int(position[i][3]))
printhnb(sky)
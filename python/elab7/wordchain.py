text="SUN TON BOW GOD LOT KID FAX BAT FAT CAR EAT FEE SEA MAP DRY SPY TAP"
s=text.split(" ")
word=[]
chain=[]
error=0
wcount=1
ccount=0
for i in range(1,len(s)):
    x=s[i-1]
    y=s[i]
    #print(x,y,i)
    for j in range(len(x)):
        #print(x[i],y[i])
        if x[j] != y[j]:
            error+=1
    #print(error)
    if error <= 2:
        wcount+=1
        error=0
    else:
        #print(error)
        #print(wcount)
        word.append(wcount)
        wcount=1
        ccount+=1
        error=0

    if i==len(s)-1:
        #print('hi')
        word.append(wcount)
        ccount+=1
#print(wcount)
print(ccount,max(word))
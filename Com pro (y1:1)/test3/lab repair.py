N=int(input("N: "))
n=N
money=0
total=[]
while n>0:
    if n>=15:
        times=n//15
        n=n-(15*(times))
        money+=(times)*3000
    if n>=10:
        times=n//10
        n=n-(15*(times))
        money+=(times)*3000
    if n>=5:
        times=n//5
        n=n-(5*times)
        money+=times*1500
    if n>=4:
        times=n//4
        n=n-(5*times)
        money+=times*1500
    if n>=2:
        times=n//2
        n=n-(2*times)
        money+=times*800
    if n>=1:
        times=n//1
        n=n-(1*times)
        money+=times*500
total.append(money)
print(min(total))

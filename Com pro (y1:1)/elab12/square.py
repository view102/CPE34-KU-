r = int(input("R: "))
c = int(input("C: "))
n = 1
result=0
while n <= r and n<= c:
   nr=r-n+1
   nc=c-n+1
   result+=nr*nc
   n+=1
print(result) 
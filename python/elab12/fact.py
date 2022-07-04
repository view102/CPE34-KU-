def isprime(n):
  if n==1:
    return False
  if n == 2:
    return True
  for i in range(2,n):
    if n%i == 0:
      return False
  return True

n = int(input("n: "))
fact=[]
while n != 1:
  for i in range(2,int(n)+1):
    if isprime(i):
      if n%i == 0:
        fact.append(i)
        n = n/i
fact.sort()
print(fact)
for i in range(len(fact)):
  print(fact[i],end=' ')
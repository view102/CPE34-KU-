def gcd(a,b):
    gcdmax=-1
    if a == 0 or b == 0:
        return max(a,b), 0
    for i in range(1,max(a,b)+1):
        if a%i == 0 and b%i == 0:
            if i>gcdmax:
                gcdmax=i
    return gcdmax, a*b/gcdmax 

a=int(input("a : "))
b=int(input("b : "))
gcd,lcm=gcd(a,b)
print(f'GCD : {gcd}')
print(f'LCM : {lcm:.0f}')
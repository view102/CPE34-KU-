class MyMath:
    def even(self,num):
        if num%2==0:
            return True
        else:
            return False
    
    def fac(self,num):
        fac=1
        while num!=0:
            fac = fac * num
            num-=1
        return fac
    
    def isprime(self,num):
        if num == 1:
            return False
        if num == 2:
            return True
        for i in range(2,num):
            if num%i!=0:
                pass
            elif num%i==0:
                return False
        return True

    def divide(self,num,k):
        if num%k==0:
            return True
        else:
            return False
    
    def tentobi(self,num):
        bi = ''
        while (num > 0):
            bi = str(num%2) + bi
            num = num // 2
        return bi

    def tentooctal(self,num):
        octal = ''
        while (num > 0):
            octal = str(num%8) + octal
            num = num // 8
        return octal

    def tentosixteen(self,num):
        Sixdict={10:'A',11:'B',12:'C',13:'D',14:'E',15:'F'}
        sixteen = ''
        while (num > 0):
            if num%16 < 10:
                sixteen = str(num%16) + sixteen
                num = num // 16
            else:
                sixteen = Sixdict[num%16] + sixteen
                num = num // 16 
        return sixteen

    def roman(self,romanum):
        if romanum>=1000:
            romanum=romanum-1000
            sym='M'
            return sym + self.roman(romanum)
        elif romanum>=900:
            romanum=romanum-900
            sym='CM'
            return sym + self.roman(romanum)
        elif romanum>=500:
            romanum=romanum-500
            sym='D'
            return sym + self.roman(romanum)
        elif romanum>=400:
            romanum=romanum-400
            sym='CD'
            return sym + self.roman(romanum)
        elif romanum>=100:
            romanum=romanum-100
            sym='C'
            return sym + self.roman(romanum)
        elif romanum>=50:
            romanum=romanum-50
            sym='L'
            return sym + self.roman(romanum)
        elif romanum>=45:
            romanum=romanum-45
            sym='XLV'
            return sym + self.roman(romanum)
        elif romanum>=40:
            romanum=romanum-40
            sym='XL'
            return sym + self.roman(romanum)
        elif romanum>=10:
            romanum=romanum-10
            sym='X'
            return sym + self.roman(romanum)
        elif romanum>=9:
            romanum=romanum-9
            sym='IX'
            return sym + self.roman(romanum)
        elif romanum>=5:
            romanum=romanum-5
            sym='V'
            return sym + self.roman(romanum)
        elif romanum>=4:
            romanum=romanum-4
            sym='IV'
            return sym + self.roman(romanum)
        elif romanum>=1:
            romanum=romanum-1
            sym='I'
            return sym + self.roman(romanum)
        else:
            return ""

    def PI(self):
        total=0
        for i in range(50):
            total+=4/((2*i + 2)*(2*i+3)*(2*i+4))*(-1)**i
        return 3+total
m=MyMath()
num=int(input("Please Enter Number : "))
div=int(input("Divide by? : "))

if m.even(num):
    print("This number is even number.")
else:
    print("This number is not even number.")

if num>20:
    print("factorial TOO LONG.")
else:
    print(f"factorial is {m.fac(num):,.0f}.")

if m.isprime(num):
    print("This number is a prime number.")
else:
    print("This number is not a prime number.")

if m.divide(num,div):
    print(f"{num} is divisible by {div}.")
else:
    print(f"{num} is not divisible by {div}.")

print(f"{num} is {m.tentobi(num)} in base 2.")
print(f"{num} is {m.tentooctal(num)} in base 8.")
print(f"{num} is {m.tentosixteen(num)} in base 16.")
print(f"{num} is {m.roman(num)} in roman numeral system.")
print(f"PI is {m.PI():.20f}")

class Rectangle:
    def __init__ (self, w, l):
        self.w=w
        self.l=l
        self.area= w * l
        self.perimeter=w*2 + l*2

    def square(self):
        if self.w == self.l:
            print("This rectangle is square too.")
        else:
            print("This rectangle is not square.")

class Triangle:
    def __init__(self, l1, l2, l3):
        self.l1=l1
        self.l2=l2
        self.l3=l3
        S=(l1+l2+l3)/2
        self.area=(S*(S-l1)*(S-l2)*(S-l3))**(1/2)
        self.perimeter=l1+l2+l3
    
    def right_Triangle(self):
        L=[self.l1,self.l2,self.l3]
        x=max(L)
        L.remove(x)
        y=L[0]
        z=L[1]
        if x**2 == y**2 + z**2:
            return "This triangle is right triangle too."
        else:
            return "This triangle is not right triangle."

class Circle:
    def __init__(self,r):
        self.r=r
        self.area=3.14*(r**2)
        self.perimeter=2*3.14*r
    
l = int(input("Enter rectangle length : "))  
w = int(input("Enter rectangle width : "))  
p1 = Rectangle(l,w)  
print(f'Area is {p1.area}.')  
print(f'Perimeter is {p1.perimeter}.')  
p1.square()

l1 = int(input("Enter triangle first side length : "))  
l2 = int(input("Enter triangle second side length : "))  
l3 = int(input("Enter triangle third side length : "))  
p2 = Triangle(l1,l2,l3)  
print(f'Area is {p2.area}.')  
print(f'Perimeter is {p2.perimeter}.')  
print(p2.right_Triangle()) 

r = int(input("Enter circle radius : "))  
p3 = Circle(r)  
print(f'Area is {p3.area}.')  
print(f'Perimeter is {p3.perimeter}.')
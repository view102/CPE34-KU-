class py_solution:
    def __init__(self,prt):
        self.prt=list(prt)
    
    def is_valid_parentheses(self):
        if len(self.prt)%2!=0:
            return False
        op=['(','[','{']
        cls=[')',']','}']
        tmp=[]
        for i in self.prt:
            if i in op:
                tmp.append(i)
            else:
                res=cls.index(i)
                if (len(tmp)>0 and op[res]==tmp[len(tmp)-1]):
                    tmp.pop()
                else:
                    return False
        if len(tmp)==0:
            return True

prt=input("input: ")
p=py_solution(prt)

if p.is_valid_parentheses():
    print("valid parentheses")
else:
    print("invalid parentheses")

chk = input()
chk1 = py_solution(chk)
print(chk1.is_valid_parentheses())
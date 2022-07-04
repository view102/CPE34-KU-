import json 

class Reviewer:
    def __init__(self,A):
        self.reviewerID = A['reviewerID']
        self.productID = A['productID']
        self.productName =A['productName']
        self.helpful = A['helpful']
        self.summary = A['summary']
        self.reviewText = A['reviewText']
        self.overall = A['overall']
        self.unixReviewTime = A['unixReviewTime']
        self.category = A['category']
        self.price = A['price']
        self.arrcategory = self.category.split('>')    
    def Word(self):
        x = self.reviewText.split()
        return len(x)    
class Product:
    def __init__(self,name,dic):
        self.name = name
        self.score = dic[0]
        self.count = dic[1]
        self.avg = float(dic[0]/dic[1])
    def __lt__(self, rhs):
        if self.avg != rhs.avg : return self.avg > rhs.avg
        else : return self.count > rhs.count
class Product2:
    def __init__(self,name,dic):
        self.name = name 
        self.avg = (dic[0] / dic[1]) 

    def __lt__(self, rhs): return self.avg > rhs.avg

def ans(m):
    if m == 1: print(f"{len(A)}")
    elif m == 2:
        s = set()
        for i in A : s.add(i.reviewerID)
        print(len(s))
    elif m == 3:
        s = set()
        for i in A : s.add(i.productName)
        print(len(s))
    elif m == 4:
        s = set()
        for i in A : s.add(i.arrcategory[0])
        print(len(s))
    elif m == 5:
        s = set()
        for i in A : s.add(i.arrcategory[1])
        print(len(s))
    elif m == 6:
        dic = dict()
        maxx = -1 
        maxxans= ''
        for i in A : 
            if not i.reviewerID in dic :
                dic[i.reviewerID] = 0 
            else : 
                dic[i.reviewerID] += 1
                if  dic[i.reviewerID] > maxx : 
                    maxx = dic[i.reviewerID]
                    maxxans= i.reviewerID
        print(maxxans)
    elif m == 7:
        dic = dict()
        lis = list()
        for i in A :
            if not i.productName in dic :
                dic[i.productName] = [int(i.overall),1]
            else : 
                dic[i.productName][0] += int(i.overall)
                dic[i.productName][1] += 1 
        for name in dic :
            p1 = Product(name,dic[name])
            lis.append(p1)
            del p1
        lis.sort()
        print(lis[0].name)
    elif m == 8:
        dic = dict()
        lis = list()
        for i in A :
            if not i.productName in dic :
                dic[i.productName] = [int(i.Word()),1]
            else : 
                dic[i.productName][0] += int(i.Word())
                dic[i.productName][1] += 1 
        for name in dic :
            p1 = Product2(name,dic[name])
            lis.append(p1)
            del p1
        lis.sort()
        print(lis[0].name)
file =  input("file name: ")
menu = int(input("input: "))
arr = [json.loads(line) for line in open(file, 'r')]
A = []
for i in arr:
    A.append(Reviewer(i))
ans(menu)
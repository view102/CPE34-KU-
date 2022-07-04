class Matrix:
    def __init__(self,func):
        self.data=func

    def det(self):
        total=(self.data[0][0]*self.data[1][1]*self.data[2][2]+self.data[0][1]*self.data[1][2]*self.data[2][0]+self.data[0][2]*self.data[1][0]*self.data[2][1])-(self.data[2][0]*self.data[1][1]*self.data[0][2]+self.data[2][1]*self.data[1][2]*self.data[0][0]+self.data[2][2]*self.data[1][0]*self.data[0][1])
        return total
    
    def plus(self,B):
        C=[]
        for i in range(len(self.data)):
            row=[]
            for j in range(len(B.data)):
                sum_plus=self.data[i][j]+B.data[i][j]
                row.append(sum_plus)
            C.append(row)
        return Matrix(C)

    def minus(self,B):
        C=[]
        for i in range(len(self.data)):
            row=[]
            for j in range(len(B.data)):
                minus_plus=self.data[i][j]-B.data[i][j]
                row.append(minus_plus)
            C.append(row)
        return Matrix(C)

    def multiply(self,B):
        C=[]
        for i in range(len(self.data)):
            row=[]
            for j in range(len(B.data)):
                total=0
                for k in range(len(B.data)):
                    total+=self.data[i][k]*B.data[k][j]
                row.append(total)
            C.append(row)
        return Matrix(C)

    def show(self):
        for i in range(3):
            for j in range(3):
                print(f'{self.data[i][j]:^6}', end = ' ')
            print()

def input_matrix():
    data = []
    for i in range(3):
        data.append([int(j) for j in input(f"Row {i+1} : ").split(' ')])
    return data

print("input row of matrix A")
A = Matrix(input_matrix())
print("input row of matrix B")
B = Matrix(input_matrix())
print(B)
print(f'Det of Matrix(A) = {A.det()}')
print(f'Det of Matrix(B) = {B.det()}')

print("Matrix(A+B) is:")
res = A.plus(B)
res.show()

print("Matrix(A-B) is:")
res = A.minus(B)
res.show()

print("Matrix(A*B) is:")
res = A.multiply(B)
res.show()

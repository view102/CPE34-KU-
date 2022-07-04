def zigzag(n):
    '''zigzag rows'''
    def compare(xy):
        x, y = xy
        return (x + y, -y if (x + y) % 2 else y)
    xs = range(n)
    return {index: n for n, index in enumerate(sorted(
        ((x, y) for x in xs for y in xs),
        key=compare
    ))}
 
 
def printzz(myarray):
    '''show zigzag rows as lines'''
    n = int(len(myarray) ** 0.5 + 0.5)
    xs = range(n)
    x=str(print('\n'.join(
        [''.join("%3i" % myarray[(x, y)] for x in xs) for y in xs]
    )))
    return x

def printmat(ans):
    for x in range(len(ans)-1,-1,-1):
        for y in range(len(ans)-1,-1,-1):
            print(f'{ans[y][x]:3.0f}',end=' ')
        print()

n=int(input(""))
x=zigzag(n)
#print(x.keys())
mat=[]
mat2=[]
for i in range(n):
    mat.append([])
i=1
for pos in x.keys():
    mat[pos[0]].append(i)
    i+=1
for i in range(len(mat)):
    mat2.append(mat[-i-1])
#print(mat)
#print(mat2)
printmat(mat2)
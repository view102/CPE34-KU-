def printS(ss):
    for i in range(len(ss)):
        for j in range(len(ss[i])):
            print(ss[i][j],end='')
        print()

def parseInput(s):
    line=[]
    tmp=[]
    for i in s:
        tmp.append(i)
        if i == '\n':
            line.append(tmp)
            tmp=[]
    return line



f='Square01.txt'
with open(f) as f:
    s=f.read()
x=parseInput(s)
printS(x)         
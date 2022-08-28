import numpy as np
'''
data = np.loadtxt('data.txt',delimiter=',')
print(data)
print(data.T[2])
print(data.shape)
print(data.size)
print(sum(data))
print(data**2)
print(data-2)

def func(x,y,sums):
    cnt = len(y)
    if len(x) < len(y):
        cnt = len(x)
    for i in range(cnt):
        x[i] = x[i] + y[i]
    sums=11
    x.append(sums)

sums=10
x = [1,2,3,4]
func(x,[5,6,7],sums)
print(x,sums)
'''
a = np.array(range(1,11))
print(sum(a**2))
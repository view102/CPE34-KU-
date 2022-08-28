import datetime
import math

x = datetime.datetime(2020, 5, 17, 12, 40, 50)
y = datetime.datetime(2020, 5, 17, 14, 40, 55)
z = datetime.datetime(2020, 5, 17, 14, 40, 50)
a = datetime.datetime(2020, 5, 17, 15, 30, 20)
b = datetime.datetime(2020, 5, 17, 14, 50, 10)
c = datetime.datetime(2020, 5, 17, 1, 4, 5)
l = datetime.time.

print(l)

xsec = int(x.strftime("%H"))*3600 + int(x.strftime("%M"))*60 + int(x.strftime("%S"))
ysec = int(y.strftime("%H"))*3600 + int(y.strftime("%M"))*60 + int(y.strftime("%S"))
avg = abs(xsec-ysec)
print("\n")
print(avg)
avgh = int((avg/60)/60)
avg = avg - avgh*3600
avgm = int(avg/60)
avg = avg - avgm*60
avgs = avg
print(avgh,avgm,avgs)
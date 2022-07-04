import csv

class Cities:
  countcity=0
  def __init__(self,city,country,lat,long,temp):
    self.city=city
    self.country=country
    self.lat=lat
    self.long=long
    self.temp=temp
    Cities.countcity+=1

file=input("Enter file name: ")#'Cities.csv'
ct=[]
with open(file) as f:
  ct_reader = csv.reader(f)
  print(ct_reader)
  next(ct_reader)
  for city in ct_reader:
    print(city)
    ct.append(city)
#print(ct[0])
temp=[]
for city in ct:
  c=Cities(city[0],city[1],city[2],city[3],city[4])
  temp.append(float(c.temp))
  del c
print(f'Minimum: {min(temp):.2f}')
print(f'Maximum: {max(temp)}')
print(f'Average temperature: {sum(temp)/len(temp):.4f}')
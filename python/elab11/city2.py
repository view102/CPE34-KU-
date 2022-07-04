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

file = input("Enter file name: ")#'Cities.csv'
city=[]
with open(file) as f:
  cityread = csv.DictReader(f)
  for c in cityread:
    city.append(c)
country={}
for c in city:
  #print(c)
  #print(c['city'],c['country'])
  #print(c)
  if c['country'] not in country:
    country[c['country']] = [float(c['temperature']),1]
  else:
    country[c['country']][0] += float(c['temperature'])
    country[c['country']][1] += 1
  #print(country)

#print(country)
for ct in country:
 # print(ct,country[ct][0],country[ct][1])
  print(ct,f'{country[ct][0]/country[ct][1]:.2f}')
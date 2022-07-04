import csv

class Cities:
  countcity=0
  def __init__(self,city,country,lat,long,temp):
    self.city=city
    self.country=country
    self.lat=lat
    self.long=long
    self.temp=float(temp)
    Cities.countcity+=1

class Country:
  def __init__(self, country, population, eu, coastline):
    self.country = country
    self.population = population
    self.eu = eu
    self.coastline = coastline

file1=input('Enter city file: ')#'Cities.csv'
file2=input('Enter country file: ')#'Countries.csv'
city=[]
country=[]
with open(file1) as f:
  cityread = csv.DictReader(f)
  for ct in cityread:
    city.append(ct)

with open(file2) as f:
  countryread = csv.DictReader(f)
  for ct in countryread:
    country.append(ct)

countrytemp={}
#print(f'{city}\n{country}')
for countries in country:
    countries = Country(countries['country'],countries['population'],countries['EU'],countries['coastline'])
    for cities in city:
      cities = Cities(cities['city'],cities['country'],cities['latitude'],cities['longitude'],cities['temperature'])
      if countries.country == cities.country:
        if countries.eu == 'no' and countries.coastline == 'yes':
          if cities.country not in countrytemp:
            countrytemp[cities.country] = [cities.temp,1]
          else:
            countrytemp[cities.country][0] += cities.temp
            countrytemp[cities.country][1] += 1

print('Average temperature of countries having coastline, but not in EU:')
for ct in countrytemp:
  print(ct,f'{countrytemp[ct][0]/countrytemp[ct][1]:.2f}')
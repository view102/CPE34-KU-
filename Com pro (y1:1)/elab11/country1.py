import csv

class Country:
  def __init__(self, country, population, eu, coastline):
    self.country = country
    self.population = population
    self.eu = eu
    self.coastline = coastline

file=input("Enter File name: ")
with open(file) as f:
  country_reader=csv.DictReader(f)
  #print(country_reader)
  for country in country_reader:
    ct=Country(country['country'],country['population'],country['EU'],country['coastline'])
    if ct.coastline == 'yes' and ct.eu == 'no':
      print(ct.country, ct.population)
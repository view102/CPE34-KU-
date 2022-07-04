import requests
import bs4
import re

class stdinfo:
  def __init__(self,name,nameth,hope,food,travel,skill,hobbies,friends):
    self.name = name
    self.nameth = nameth
    self.hope = hope.text
    self.food = food.text
    self.travel = travel.text
    self.skill = skill.text
    self.hobbies = hobbies.text
    self.friends = friends

url = 'http://earth.mikelab.net:8080/~std46'
Header = {'User-Agent' : 'Pruck,std46,pruck.ua@ku.th'}
page = requests.get(url , headers = Header)
#print(page)
page.encoding = 'uft-8'
s=page.text
pagecode = bs4.BeautifulSoup(page.text , 'html.parser')
#print(pagecode.prettify())
name = pagecode.find_all(id="myname")
nameth = pagecode.find_all(id="myname_th")
key = pagecode.find_all('th')
value = pagecode.find_all('td')
dicts={}
#print(key, value)
for i in range(len(key)):
  if key[i].text not in dicts.keys():
    dicts[key[i].text] = value[i].text
#print(dicts) 
#print(name,nameth)
friend=[]
button = pagecode.find_all('button')
for i in range(len(button)):
  #print(button[i]['onclick'])
  #y=button[i].text
  p=re.findall(r'std[^/]+',button[i]['onclick'])
  #print(p)
  if 'std' in button[i]['onclick']:
    #x=list(y)
    #print(x)
    friend.append(p[0]) 
#print(friend)
#print(button)
std = stdinfo(name[0].text,nameth[0].text,value[0],value[1],value[2],value[3],value[4],friend)
print(std.food)
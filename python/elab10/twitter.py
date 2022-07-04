#class twitter:
import json

def readfile(f):
  with open(f) as f:
    r=f.read()
  j=json.loads(r)
  return j

def first(f):
  return print(len(f))

def secondthird(f):
  user={}
  name=[]
  mymax=-1
  for lis in f:
    if lis['author'] not in user.keys():
      user[lis['author']] = 1
    else:
      user[lis['author']] += 1
      if user[lis['author']] > mymax:
        mymax = user[lis['author']]
        
  for key in user.keys():
    if user[key] == mymax:
      name.append(key)
  return len(user), name

def fourth_eighth(f):
  topic=[]
  alert=[]
  unimportant=[]
  wordmax=-1
  lan=False
  for dic in f:
    word=[]
    if dic['topic'] not in topic:
      topic.append(dic['topic'])
    if dic['topic_priority'] == 'ALERT':
      alert.append(dic['topic_priority'])
    elif dic['topic_priority'] == 'UNIMPORTANT':
      unimportant.append(dic['topic_priority'])
    if dic['language'] != 'EN':
      lan=True
    for w in dic['text'].split():
      if w != '':
        word.append(w)
    if len(word) > wordmax:
      wordmax=len(word)
      xx=word
  #print(xx)
  return len(topic),len(alert),len(unimportant),lan,wordmax

file=input('File name: ')
twit=readfile(file)
n=int(input('input: '))
#print(twit[0],type(twit[0]))

#first(twit)
x,y=secondthird(twit)
#print(x,y)
topic,alert,unimp,en,word=fourth_eighth(twit)
#print(topic,alert,unimp,en,word)

if n==1:
  first(twit)
elif n==2:
  print(x)
elif n==3:
  for name in y:
    print(name)
elif n==4:
  print(topic)
elif n==5:
  print(alert)
elif n==6:
  print(unimp)
elif n==7:
  print(en)
elif n==8:
  print(word)
import json
def ans(m):
    if m == 1: print(f"{len(A)}")
    elif m == 2: 
        s = set()
        for i in A : s.add(i['author'])
        print(len(s))
    elif m == 3:
        dic = dict()
        for i in A:
            if not i['author'] in dic : dic[i['author']] = 1
            else : dic[i['author']]+=1
            maxx = -1
        for i in dic:
            if dic[i] > maxx : maxx = dic[i]
        for i in dic :
            if dic[i] == maxx : 
                print(i) 
        
    elif m == 4:
        s = set()
        for i in A : s.add(i['topic'])
        print(len(s))
    elif m == 5:
        count = 0 
        for i in A:
            if i['topic_priority'] == 'ALERT' : count +=1
        print(count)
    elif m == 6:
        count = 0 
        for i in A:
            if i['topic_priority'] == 'UNIMPORTANT' : count +=1
        print(count)
    elif m == 7 :
        check = False
        for i in A:
            if i['language'] != 'EN' and i['language'] != 'TH' : 
                check = True 
                break
        print(check) 
    elif m == 8:
        maxx = -1
        for i in A:
            if len(i['text'].split()) > maxx : maxx = len(i['text'].split())
        print(maxx)
file = input("File name: ")
menu = int(input("input: "))
f = open(file,) 
A = json.load(f) 
f.close()

ans(menu)
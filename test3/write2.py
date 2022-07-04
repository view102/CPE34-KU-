f='out2.csv'
out=[]
with open(f) as f:
    r=f.readlines()
    for i in r:
        row=[]
        for j in i.strip().split(','):
            row.append(j)
        out.append(row)
#print(out[:5])
out.pop(0)

def first(out):
    mymax=-999999999
    language={}
    language2=[]
    count=[]
    for i in range(len(out)):
        if out[i][4] not in language.keys():
            language[out[i][4]] = 1
            language2.append(out[i][4])
            count.append(1)
        else:
            language[out[i][4]] += 1
            if language[out[i][4]] > mymax:
                mymax = language[out[i][4]]
                name = out[i][4]
            index=language2.index(out[i][4])
            count[index]+=1
    maxc=max(count)
    ind=count.index(maxc)
    count.remove(maxc)
    language2.remove(name)
    max2=max(count)
    ind2=count.index(max2)
    print(len(language))
    print(name)
    print(language2[ind2])

def second(out):
    mymax=-999999999
    lic={}
    lic2=[]
    count=[]
    for i in range(len(out)):
        if out[i][2] not in lic.keys():
            lic[out[i][2]] = 1
            lic2.append(out[i][2])
            count.append(1)
        else:
            lic[out[i][2]] += 1
            if lic[out[i][2]] > mymax:
                mymax = lic[out[i][2]]
                name = out[i][2]
            index=lic2.index(out[i][2])
            count[index]+=1
    maxc=max(count)
    ind=count.index(maxc)
    count.remove(maxc)
    lic2.remove(name)
    max2=max(count)
    ind2=count.index(max2)
    print(len(lic))
    print(name)
    print(lic2[ind2])

def third(out):
    version=[]
    for i in range(len(out)):
        version.append(out[i][3])
    maxx=max(version)
    index=version.index(maxx)
    print(maxx)
    print(out[index][0])

def fourth(out):
    size=[]
    n=0
    total=0
    for i in range(len(out)):
        if out[i][4] == 'C#':
            size.append(out[i][6])
            n+=1
            total+=float(out[i][6])
    print(f'{total/n:.3f}')

def fifth(out):
    plat=[]
    count=[]
    for i in range(len(out)):
        if out[i][5] == 'GitHub':
            if out[i][1] not in plat:
                plat.append(out[i][1])
                count.append(1)
            else:
                index=plat.index(out[i][1])
                count[index]+=1
    minn=min(count)
    indmin=count.index(minn)
    minplat=[]
    for i in range(len(count)):
        if count[i] == minn:
            minplat.append(plat[i])
    print(minplat,minn)

def eighth(out):
    project=[]
    for i in range(len(out)):
        if 'py' in out[i][0].lower():
            project.append(out[i][0])
    #print(project)
    print(len(project),'projects')

first(out)
print()
second(out)
print()
third(out)
print()
fourth(out)
print()
eighth(out)
print()
fifth(out)
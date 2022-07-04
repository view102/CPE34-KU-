def substring(text, ss):
    if len(text) < len(ss):
        return text
    if text[:len(ss)] == ss:
        return '[' + ss + ']' + substring(text[len(ss):],ss)
    else:
        return text[0] + substring(text[1:],ss)

def dummy(text,ss):
    tx=list(text)
    s=list(ss)
    error=0
    if len(tx) < len(s):
        return text
    for i in range(len(s)):
        if tx[i] != s[i]:
            res=i
            error+=1
    if error>1:
        return text[0] + dummy(text[1:],ss)
    elif error==1:
        #print(s)
        s[res]='?'
        string=''
        #print(s)
        for j in range(len(s)):
            string+=str(s[j])
        return '[' + string + ']' + dummy(text[len(ss):],ss)

x='acababababaccbabab'
ss='aba'
#print(dummy(x,ss))
if ss in x:
    print(substring(x,ss))
else:
    print(dummy(x,ss))
    
# Prog-12: Tweeter Data Analytics
# Fill in your ID & Name
# ...
# Declare that you do this by yourself

import datetime

def to_epoch(date_time):
    d = datetime.datetime.strptime(date_time, '%Y-%m-%d %H:%M:%S')
    return d.timestamp()

def read_tweets(filename):
    f = open(filename)
    tweets = [tuple(line.strip().split(',')) 
              for line in f.readlines()]
    f.close()
    return tweets

def prt(x):
    print('\n'.join(str(e) for e in x))
    print('-----------------')

def test(filename, K, S):
    tweets = read_tweets(filename)
    print(filename, 'K=', K, 'S=', S)
    prt( top_K_tweeters(tweets, K) )
    prt( top_K_tweeters_in_S_seconds(tweets, K, S) )
    prt( top_K_common_tweet_pairs(tweets, K) )
    prt( top_K_common_tweet_triples(tweets, K) )

def main():
    test('tweet_info_mini.csv', 5, 3)
    test('tweet_info.csv', 10, 24*60*60)
#----------------------------------

def splitmsg(tweets) :
    msg = dict()
    for i in range(len(tweets)) :
        user = tweets[i][1]
        if user not in msg :
            msg[user] = set()
        msg[user].add(tweets[i][2]) 
    return msg

def sorttweeter(x,K) :
    x.sort(reverse=True)
    i = 0
    while i < len(x) :
        j = i
        while j < len(x) and x[j][0] == x[i][0] :
            j += 1
        x = x[:i] + sorted( [(a,b) for (b,a) in x[i:j]] ) + x[j:]
        i = j
    return x[:K]
#----------------------------------

def top_K_tweeters(tweets, K):
    tweeter = dict()
    for t in tweets :
        if t[1] not in tweeter :
            tweeter[t[1]] = 0
        tweeter[t[1]] += 1
    x = [(b,a) for a,b in tweeter.items()]
    return sorttweeter(x,K)
#---------------------------------
def top_K_tweeters_in_S_seconds(tweets, K, S):
    msg = dict()
    for i in range(len(tweets)) :
        user = tweets[i][1]
        if user not in msg :
            msg[user] = []
        msg[user].append(to_epoch(tweets[i][0]))
    tweeter = dict()
    for user in msg :
        m = msg[user]
        i = 0
        j = 0
        while j < len(m) :
            if m[j]-m[i] < S:
                j += 1
            else :
                i += 1
                j += 1
        tweeter[user] = j-i
    x = [(b,a) for a,b in tweeter.items()]
    return sorttweeter(x,K)
#---------------------------------
def top_K_common_tweet_pairs(tweets, K):
    ans = [((0,0),-1)]*K
    #print(tweets[:5], K,'!!!!!!!!')
    msg = splitmsg(tweets)
    #print(msg,'!!!!!!')
    res=[]
    for i in msg.keys():
        res.append(i)
    u=sorted(res)
    for i in range(len(msg)) :
        user = u[i]
        m = msg[user]
        if len(m) > min([e for (p,e) in ans]) :
            for j in range(i+1,len(msg)) :
                frd = u[j]
                fm = msg[frd]
                n = len(m.intersection(fm))
                if n > min([e for (p,e) in ans]) :
                    k = 0
                    for k in range(K) :
                        if ans[k][1] == min([e for (p,e) in ans]) : break
                    ans[k] = ((user,frd),n)
    tmp=[]
    x=[]
    for i in ans:
        if i != ((0,0),-1):
            tmp.append(i)
    for (a,b) in tmp:
        x.append((b,a))

    return sorttweeter(x,K)
#---------------------------------
def top_K_common_tweet_triples(tweets, K):
    ans = [((0,0,0),-1)]*K
    minval = -1
    msg = splitmsg(tweets)
    res=[]
    for i in msg.keys():
        res.append(i)
    u=sorted(res)
    for i in range(len(u)) :
        p1 = u[i]
        m1 = msg[p1]
        if len(m1) > minval :
            for j in range(i+1,len(msg)) :
                p2 = u[j]
                m2 = msg[p2]
                if len(m2.intersection(m1)) > minval :
                    for k in range(j+1,len(msg)) :
                        p3 = u[k]
                        m3 = msg[p3]
                        n = len(m1.intersection(m2.intersection(m3)))
                        if n > minval :
                            idx = 0
                            for idx in range(K) :
                                if ans[idx][1] == minval : break
                            ans[idx] = ((p1,p2,p3),n)
                            minval = min([e for (p,e) in ans])
    tmp=[]
    x=[]
    for i in ans:
        if i != ((0,0),-1):
            tmp.append(i)
    for (a,b) in tmp:
        x.append((b,a))
    return sorttweeter(x,K)

#----------------------------------
main()

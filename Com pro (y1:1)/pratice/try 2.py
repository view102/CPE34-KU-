n = int(input(''))
bids = {}
bidder = []
namebidder = []
item = []
for _ in range(n):
    bid = input().split(' ')
    bidder.append(bid)
    if bid[1] not in namebidder:
        namebidder.append(bid[1])
    if bid[2] not in item:
        item.append(bid[1])
    if bid[0] == 'W':
        mymax = 0
        name = '-'
        for i in range(len(bidder)):
            if bidder[i][2] == bid[2]:
                if bidder[i][1] != bid[1]:
                    if int(bidder[i][3]) > mymax:
                        mymax = int(bidder[i][3])
                        name = bidder[i][1]
                else:
                    res = i
        #bidder.pop(res)
        for i in bids.keys():
            if bids[i][0] == bid[1] and i == bid[2]:
                bids[i][0] = name
                bids[i][1] = mymax
    else:
        if bid[2] not in bids:
            bids[bid[2]] = [bid[1], int(bid[3])]
        else:
            if int(bid[3]) > bids[bid[2]][1]:
                bids[bid[2]][1] = int(bid[3])
                bids[bid[2]][0] = bid[1]
bidders = {}
for key in bids.keys():
    if bids[key][0] not in bidders:
        bidders[bids[key][0]] = [bids[key][1],[key]]
    else:
        bidders[bids[key][0]][0] += bids[key][1]
        bidders[bids[key][0]][1].append(key)
for name in namebidder:
    if name not in bidders.keys():
        bidders[name] = 0
for name in bidders.keys():
    if name != '-':
        print() 
print(bids)
print(bidders)
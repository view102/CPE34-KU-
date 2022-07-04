n = int(input())
dic_price = {}
dic_who_get = {}
all_bidder = []
all_bidder_ans = []
all_pro = []
check = False
get_winner = []
winner_winner_chicken_dinner = {}

for i in range(n) :  #get all information
    m = input().split()
    all_bidder.append(m)
    if m[2] not in all_pro :
        all_pro.append(m[2])
    if m[1] not in all_bidder_ans :
        all_bidder_ans.append(m[1])

for i in range(10) :     
    for row in all_bidder :   #remove and find W bidder
        if "W" in row :
            user,pro = row[1] ,row[2]
            check = True  
            if check :
                i = 0
                while i < len(all_bidder) :      #remove no need bidder  
                    if user in all_bidder[i]:
                        if pro in all_bidder[i] :
                            all_bidder.remove(all_bidder[i])
                            i -= 1
                    i += 1

for k in all_bidder :   #know all price
    if len(k) >3 :
        if k[2] not in dic_who_get :
            dic_who_get[k[2]] = k[3]
        else :
            if k[3] > dic_who_get[k[2]] :
                dic_who_get[k[2]] = k[3]

print(all_bidder)

for m in all_bidder :   #get winner bidder only
    if len(m) > 3 :
        for key in dic_who_get  :
            if dic_who_get[key] == m[3] and key in m :
                    get_winner.append([ m[1],m[2],m[3] ])
        

for m in get_winner :      #get price for all bidders who get product
    if m[0] not in dic_price :
        dic_price[m[0]] = int(m[2])
    else :
        dic_price[m[0]] += int(m[2])

for m in get_winner :   #get pro for bidder who wins
    if m[0] not in winner_winner_chicken_dinner :
        winner_winner_chicken_dinner[m[0]] = [m[1]]
    else :
        winner_winner_chicken_dinner[m[0]].append(m[1])
        winner_winner_chicken_dinner[m[0]].sort()
        
all_bidder_ans.sort()
for i in range(len(all_bidder_ans)) :   
    if all_bidder_ans[i] not in dic_price :
        print(all_bidder_ans[i] + ": $0")
    else :
        print(all_bidder_ans[i] + ": $" + str(dic_price[all_bidder_ans[i]]) + " -> " + \
              " ".join(winner_winner_chicken_dinner[all_bidder_ans[i]]) )

print(get_winner)
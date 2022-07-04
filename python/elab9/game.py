import numpy as np

class character:
    def __init__(self,blood):
        self.blood=blood
        
    def attacked(dm):
        self.blood=self.blood-dm

    def heal():
        self.blood+=20

blood=int(input("Blood Start: "))
knight=character(blood)
mons=character(blood)
turn=1
combo=0
X = np.random.RandomState(1)

while knight.blood > 0 and mons.blood > 0:
    if turn%2!=0:
        do=input("Attack(a) or Heal(h): ")
        if do == 'a':
            mons.blood-=(10+(combo*2))
            combo+=1
            if mons.blood>0:
                print(f"Monster's HP left {mons.blood}")
            else:
                print("Monster's HP left 0")
        elif do == "h":
            knight.blood+=20
            print(f"Your HP left {knight.blood}")
            combo=0
    else:
        dm=X.randint(1,40)
        knight.blood-=dm
        if knight.blood>0:
            print(f"Monster's turn : Your HP left {knight.blood}")
        else:
            print("Monster's turn : Your HP left 0")
    turn+=1

if knight.blood >0:
    print("You win.(^_^)")
else:
    print("You lose and die.(T_T)")

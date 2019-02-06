import random
def vytlac():
    for i in range(len(mesto)):
        print(mesto[i],end='')
    print()
mesto = ['HOME']
#n = int(input('Zadaj n: '))
n = 11
for i in range(n):
    mesto.append('.')
mesto.append('PUB')
mesto[n//2+1] = 'O'
vytlac()
pozicia = n//2+1
poc = 0
posun=[-1,1]
while poc<19:
    nahoda = random.randint(0,1)
    if pozicia + posun[nahoda]==0 or pozicia + posun[nahoda]==len(mesto)-1:
        break
    mesto[pozicia],mesto[pozicia+posun[nahoda]]=mesto[pozicia+posun[nahoda]],mesto[pozicia]
    pozicia += posun[nahoda]
    poc += 1
    vytlac()
import random
def zisti_index(a):
    for i in range(len(zt)):
        if slovnik[i]==a:
            return i
nt = 'Ako sa dneska mas?'
lst = []
nahodne_cisla = []
for i in range(len(nt)):
    lst.append(i)
while len(nahodne_cisla)!=len(nt):
    a = random.randint(0,len(nt)-1)
    if a not in nahodne_cisla:
        nahodne_cisla.append(a)
slovnik = dict.fromkeys(lst)
for i in range(len(slovnik)):
    slovnik[i]=nahodne_cisla[i]
#print(slovnik)
zt = ''
for i in range(len(slovnik)):
    zt+=nt[slovnik.get(i)]
print(nt)
print(zt)
rozlustene = ''
for i in range(len(slovnik)):
    rozlustene+=zt[zisti_index(i)]
print(rozlustene)
import random
lst = []
for i in range(101):
    lst.append(random.randint(0,20))
mnozina = set()
for item in lst:
    mnozina.add(item)
mnozina = sorted(list(mnozina))
slovnik = dict.fromkeys(mnozina)
for key in slovnik:
    slovnik[key] = 0
for item in lst:
    slovnik[item]+=1
for item in mnozina:
    print(item,':','*'*slovnik[item])

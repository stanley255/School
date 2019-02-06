import random
lst = []
for i in range(10):
    lst.append(random.randint(0,9))
print(lst)

unique = []
for i in range(len(lst)):
    poc = 0
    for j in range(len(unique)):
        if unique[j]==lst[i]:
            poc += 1
    if poc == 0:
        unique.append(lst[i])
print(unique)




'''
mnozina = set()
for item in lst:
    mnozina.add(item)
mnozina = list(mnozina)
print(mnozina)
'''
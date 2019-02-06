import random
lst = []
for i in range(100):
    lst.append(random.randint(0,20))
print(lst)
unique = set()
for item in lst:
    unique.add(item)
unique = sorted(list(unique))
frequency = dict.fromkeys(unique)
for key in frequency:
    frequency[key]=0
for item in lst:
    frequency[item]+=1
for key in frequency:
    print(key,'*'*frequency[key],end='')
    print()

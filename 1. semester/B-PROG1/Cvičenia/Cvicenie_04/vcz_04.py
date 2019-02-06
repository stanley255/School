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
unique.sort()
print(unique)

for i in range(len(unique)):
    poc = 0
    for j in range(len(lst)):
        if unique[i]==lst[j]:
            poc += 1
    print(unique[i],'*'*poc)
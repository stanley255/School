import random
lst = []
for i in range(10):
    lst.append(random.randint(1,10))
x = int(input('Zadaj k: '))
lst1 = lst[len(lst)-x:]
res = []
res.extend(lst1)
res.extend(lst[:len(lst)-x])
print(lst)
print(res)
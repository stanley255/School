import random
def hladaj(lst,x):
    for i in range(len(lst)):
        if lst[i]==x:
            return i
    return -1

lst = []
for i in range(10):
    lst.append(random.randint(1,10))
print(lst)
x = int(input('Zadaj x: '))
print(hladaj(lst,x))

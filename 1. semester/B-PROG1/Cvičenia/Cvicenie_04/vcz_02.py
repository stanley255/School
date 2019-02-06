import random
lst = []
for i in range(10):
    lst.append(random.randint(0,9))
print(lst)
n = int(input('Zadaj n: '))
pc = 0
for item in lst:
    if item == n:
        pc += 1
print('Zadane cislo sa v liste nachadza:',pc)
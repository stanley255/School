import random
lst = []
for i in range(10):
    lst.append(random.randint(1,10))
print(lst)
min = 0
for i in range(1,len(lst)):
    if lst[min]>lst[i]:
        min = i
print('Pozicia:',min,'\nHodnota:',lst[min])
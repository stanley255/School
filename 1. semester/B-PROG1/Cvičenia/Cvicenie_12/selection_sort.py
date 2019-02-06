import random
lst = []
for i in range(5):
    lst.append(random.randint(0,9))
print(lst)
k = 0
while k!=len(lst):
    min = k
    for i in range(k,len(lst)):
        if lst[min]>lst[i]:
            min = i
    lst[min],lst[k]=lst[k],lst[min]
    k += 1
print(lst)
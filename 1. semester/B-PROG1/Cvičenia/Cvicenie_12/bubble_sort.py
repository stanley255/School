import random
lst = []
for i in range(5):
    lst.append(random.randint(0,9))
print(lst)
for i in range(len(lst)-1):
    for j in range(len(lst)-i-1):
        if lst[j]>lst[j+1]:
            lst[j],lst[j+1]=lst[j+1],lst[j]
print(lst)
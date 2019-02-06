import random
lst = []
for i in range(5):
    lst.append(random.randint(0,9))
print(lst)
for i in range(1,len(lst)):
    k=i
    while lst[k]<lst[k-1] and k>0:
        lst[k],lst[k-1]=lst[k-1],lst[k]
        k -= 1
print(lst)
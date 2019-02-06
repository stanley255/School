import math
lst = []
for i in range(2,1000):
    lst.append(i)
j = 2
while j<len(lst):
    new_lst = []
    for i in range(len(lst)):
        if lst[i]%lst[j]!=0:
            new_lst.append(lst[i])
    lst = new_lst
    j += 1
for item in lst:
    print(item)
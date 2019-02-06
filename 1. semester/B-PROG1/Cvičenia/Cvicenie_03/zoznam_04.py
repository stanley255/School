import random
lst = []
for i in range(10):
    lst.append(random.randint(1,10))
print(lst)
max = 0
for i in range(1,len(lst)):
    if lst[max]<lst[i]:
        max = i
print('Maximum je:',lst[max])
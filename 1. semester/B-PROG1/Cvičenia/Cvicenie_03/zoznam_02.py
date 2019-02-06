lst = []
for i in range(10):
    lst.append((2^i)%113)
k = int(input('Zadaj k: '))
print(lst)
print(lst[len(lst)-k:])
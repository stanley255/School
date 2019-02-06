import random
def binary_search(x):
    a,b = 0, len(lst)
    while a != b:
        middle = (a + b) // 2
        if lst[middle] >= x:
            b = middle
        else:
            a = middle + 1
        if x == lst[a]:
            return True
    return False

lst = []
for i in range(5):
    lst.append(random.randint(0,9))
lst.sort()
print(lst)
print(binary_search(int(input('Zadaj x: '))))
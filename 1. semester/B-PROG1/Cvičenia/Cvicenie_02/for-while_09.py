n = int(input('Zadaj n: '))
res = []
while n>0:
    res.append(n%2)
    n = n//2
print(res[::-1])
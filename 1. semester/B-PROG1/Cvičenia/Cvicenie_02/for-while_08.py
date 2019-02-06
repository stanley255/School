n = int(input('Zadaj n: '))
delitele = 0
for i in range(2,n):
    if n%i == 0:
        delitele += 1
if (delitele==0) and (n>1):
    print('Zadane n je prvocislo')
else:
    print('Zadane n nie je prvocislo')
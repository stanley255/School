n = int(input('Zadaj n: '))
poc = 1
for i in range(n):
    print(' '*(n-i-1),end='')
    print(('*'*poc),end='')
    print()
    poc += 2
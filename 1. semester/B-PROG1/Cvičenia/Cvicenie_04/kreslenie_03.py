n = int(input('Zadaj n: '))
m = int(input('Zadaj m: '))
poc = 1
for i in range(n):
    print(' '*(n-i-1),end='')
    for j in range(poc):
        if m+j<10:
            print(m+j,end='')
        else:
            print((m+j)%10,end='')
    print()
    poc += 2

n = int(input('Zadaj n: '))
poc = 1
for i in range(2*n-1):
    for j in range(poc):
        print('*',end='')
    print()
    if (i>=(2*n-1)//2):
        poc -= 1
    else:
        poc += 1

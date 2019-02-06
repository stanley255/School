def vypis():
    for i in range(n):
        for j in range(n):
            print(pole[i][j], end='')
        print()
def vytvorenie_pola():
    global pole
    pole = [[] for j in range(n)]
    for i in range(n):
        for j in range(n):
            pole[i].append(' ')
    for i in range(n):
        pole[i][k - 1] = '*'
        pole[i][k + 1] = '*'
        pole[k - 1][i] = '*'
        pole[k + 1][i] = '*'
    for i in range(n):
        pole[k][i] = ' '
        pole[i][k] = ' '
    pole[k][0] = '*'
    pole[k][n - 1] = '*'
    pole[0][k] = '*'
    pole[n - 1][k] = '*'
n = 9
k = (n-1)//2
vytvorenie_pola()
vypis()
def prvocislo(x):
    if x>1:
        for i in range(2,x):
            if x%i==0:
                return False
        return True
    return False
#print(prvocislo(int(input('Zadaj cislo: '))))
for i in range(int(input('Zadaj cislo: '))+1):
    if prvocislo(i):
        print(i)
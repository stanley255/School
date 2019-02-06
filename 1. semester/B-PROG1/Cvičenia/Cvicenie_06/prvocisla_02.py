def delitelnost(a,d):
    if a%d==0:
        return True
    else:
        return False
def test_prvociselnosti(a):
    for i in range(2,a):
        if delitelnost(a,i):
            return False
    if a>1:
        return True
    else:
        return False
#print(test_prvociselnosti(int(input('Zadaj cislo, ktore chce over pre prvociselnost: '))))

for i in range(1000):
    if test_prvociselnosti(i):
        print(i)
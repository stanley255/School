a = int(input('Zadaj cislo a: '))
b = int(input('Zadaj cislo b: '))
c = int(input('Zadaj cislo c: '))
if a>b:
    b,a=a,b
if b>c:
    b,c=c,b
if a>b:
    a,b=b,a
print(a,b,c)
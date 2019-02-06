a = int(input('Zadaj cislo a: '))
b = int(input('Zadaj cislo b: '))
c = int(input('Zadaj cislo c: '))
max = a
if b>max:
    max = b
if c>max:
    max = c
min = a
if b<min:
    min = b
if c<min:
    min = c
print('Maximum:',max)
print('Minimum:',min)
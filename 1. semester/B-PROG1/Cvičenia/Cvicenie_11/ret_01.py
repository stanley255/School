def pocitaj(ret,char):
    ret = ret.lower()
    char = char.lower()
    poc = 0
    for znak in ret:
        if znak == char:
            poc += 1
    return poc
print('Ahoj','a')
print(pocitaj('Ahoj','a'))
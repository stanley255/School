def pocitaj(ret,char):
    ret = ret.lower()
    char = char.lower()
    poc = 0
    for znak in ret:
        if znak == char:
            poc += 1
    return poc

def F(lst):
    max = 0
    for i in range(1,len(lst)):
        if pocitaj(lst[max],'a')<pocitaj(lst[i],'a'):
            max = i
    return lst[max]
print(F(['aa','aaa','cbfdaa']))
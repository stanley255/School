def F1(prvok, s1):
    for cislo in s1:
        if prvok == cislo:
            return True
    return False

def F2(s1,s2):
    prienik = set()
    for cislo in s1:
        if F1(cislo,s2):
            prienik.add(cislo)
    return prienik

print(F2({1,2,3,4},{3,4,6,7}))
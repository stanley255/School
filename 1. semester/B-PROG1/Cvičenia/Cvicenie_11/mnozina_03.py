def F1(prvok,s1):
    for cislo in s1:
        if prvok == cislo:
            return True
    return False

def F3(s1,s2):
    rozdiel = set()
    for cislo in s1:
        if F1(cislo,s2):
            rozdiel.add(cislo)
    for item in rozdiel:
        s1.remove(item)
    return s1

print(F3({1,2,3,4,5}, {3, 4, 6, 7}))

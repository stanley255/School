def F1(prvok,s1):
    for cislo in s1:
        if prvok == cislo:
            return True
    return False
s1 = {1,3,5,7,9}
print(F1(7,s1))
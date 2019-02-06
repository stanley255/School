def nta_mocnina(a,n):
    return a**n
def male_mocniy(a,hranica):
    poc = 1
    while nta_mocnina(a,poc)<hranica:
        print(nta_mocnina(a,poc))
        poc += 1
male_mocniy(2,1025)
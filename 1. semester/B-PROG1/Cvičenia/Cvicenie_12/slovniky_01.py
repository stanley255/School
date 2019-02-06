def F1(lst):
    znamky = ['A','B','C','D','E','FX']
    slovnik = dict().fromkeys(znamky)
    for key in slovnik:
        slovnik[key]=0
    for item in lst:
        slovnik[item]+=1
    return slovnik

def F2(slovnik):
    for key in slovnik:
        print(key,':','*'*slovnik[key],end='')
        print()

L=['FX','FX','E','FX','B','C','A','E']
#print(F1(L))
F2(F1(L))
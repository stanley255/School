def body(ziak):
    ziak.split(' ')
    return ziak[1]
def meno(ziak):
    ziak.split(' ')
    return ziak[0]
#ziaci = ['Jano 50','Jozo 20','Adam 39','Marek 40']
#print(sorted(ziaci,key=body,reverse=True))
#print(sorted(ziaci,key=meno))
ziaci = ['Jano 50','Jozo 20','Adam 39','Marek 40']
s = sorted(ziaci,key=meno)
print(sorted(s,key=body))
